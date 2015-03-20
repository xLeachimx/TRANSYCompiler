def convertToObj doc
	doc.partition('.')[0]+'.o'
end

def isProperFile? name
	temp = File.extname(name)
	return temp == '.c' || temp == '.cpp'
end

def dependencies file, srcdir
	handle = File.new(file,'r')
	contents = handle.read
	handle.close
	contents = contents.split("\n")
	contents.map!{|l| l.strip().rstrip}
	contents.delete_if{|s| !s.start_with?('#include')}
	contents.delete_if{|s| s.include?('<')}
	contents.map!{|l| l[/".+"/]}
	contents.map!{|l| l[1...l.length-1]}
	contents.map!{|l| srcdir + l}
	return contents
end

def createMakefileFromList docs, main, name, srcdir
	docs.delete_if{|d| !isProperFile?(d) || d==main}
	makefile = "COMPILED_FILES = " + docs.map{|d| srcdir + convertToObj(d)}.join(' ') +
				"\nSOURCEDIR = #{srcdir}\nPROGNAME = #{name}\n\nall: main\n"
	makefile += "main: $(COMPILED_FILES) \n"
	makefile += "\tg++ " + srcdir+main + " $(COMPILED_FILES) -o $(PROGNAME)\n\n"
	docs.each do |d|
		extension = File.extname(d)
		if(extension == '.cpp' || extension == '.c')
			dep = dependencies(srcdir+d,srcdir)
			objdep = dep.map{|de| convertToObj(de)}.delete_if{|de| de == (srcdir + convertToObj(d))}
			makefile += srcdir + convertToObj(d) + ': ' + srcdir + d + ' ' + dep.join(' ') + ' ' + objdep.join(' ') +"\n"
			makefile += "\tcd $(SOURCEDIR) && \\\n"
			makefile += "\tg++ " + d + " -c\n\n"
		end
	end
	makefile += "clean:\n\trm $(SOURCEDIR)*.o"
	return makefile
end

temp = File.new('makefile','w')
temp.puts(createMakefileFromList(Dir.entries('src'),'compiler.cpp','compiler','src/'))
temp.close()