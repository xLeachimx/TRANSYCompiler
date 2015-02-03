# This file generates large file on demand that
# Have different names and the same content

def makeFile filename, message
  making = File.open(filename, "w")
  making.puts(message)
  making.close
end

def getListOfFilesToMake
  input = ""
  files = []
  print "Name of File:"
  input = gets.chomp
  until input === "" do
    files.push(input);
    print "Next File:"
    input = gets.chomp
  end
  return files
end

files = getListOfFilesToMake
print "Generic Message:"
messFile = gets.chomp
messContent = File.open(messFile, "r")
mess = messContent.read
messContent.close
for f in files
  makeFile(f,mess)
end
