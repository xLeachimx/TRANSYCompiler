# This file counts the lines in multiple files

def isProperFile? name
  temp = File.extname(name)
  return temp == '.c' || temp == '.cpp' || temp == '.hpp' || temp == '.cpp'
end

def getListOfFiles
  files = Dir.entries('src').delete_if{|d| !isProperFile?(d)}
end

files = getListOfFiles
count = 0
for f in files
  file = File.open('src/'+f,'r')
  count += file.read().split("\n").length()
  file.close
  contents.map!{|l| l.strip()}
  contents.delete_if{|l| l.start_with?('//')}
  contents.delete_if{|l| l.start_with?('*')}
  contents.delete_if{|l| l.start_with?('/*')}
  count += contents.length()
end

puts "Those files have " + count.to_s + " line in total"
