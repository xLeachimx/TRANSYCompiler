def convertToObj doc
	doc.partition('.')[0]+'.o'
end

def isProperFile? name
	temp = File.extname(name)
	return temp == '.c' || temp == '.cpp'
end

def createMakefileFromList docs, main, name, srcdir
	makefile = "SOURCEDIR = #{srcdir}\nPROGNAME = #{name}\n\nall: main\n"
	docs.delete_if{|d| !isProperFile?(d)}
	docs.each do |d|
		extension = File.extname(d)
		if(extension == '.cpp' || extension == '.c')
			if(d != main)
				makefile += convertToObj(d) + ":\n"
				makefile += "\tcd $(SOURCEDIR) && \\\n"
				makefile += "\tg++ " + d + " -c\n\n"
			else
				temp = docs.map{|d| convertToObj(d)}.join(' ')
				makefile += 'main: ' + temp + "\n"
				makefile += "\tcd $(SOURCEDIR) && \\\n"
				makefile += "\tg++ " + main + ' ' + temp + " -o $(PROGNAME)\n"
				makefile += "mv $(SOURCEDIR)$(PROGNAME) ./\n\n"
			end
		end
	end
	makefile += "clean:\n\trm $(SOURCEDIR)*.o"
	return makefile
end

temp = File.new('mfile','w')
temp.puts(createMakefileFromList(Dir.entries('src'),'compiler.cpp','compiler','src/'))
temp.close()