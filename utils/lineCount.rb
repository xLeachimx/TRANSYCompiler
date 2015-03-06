# This file counts the lines in multiple files

def getListOfFilesToMake
  files = [
           'compiler.cpp',
           'compiler.hpp',
           'preprocess.hpp',
           'preprocess.cpp',
           'symtable.hpp',
           'symtable.cpp',
           'table.cpp',
           'table.hpp',
           'taread.cpp',
           'taread.hpp',
           'tawrite.hpp',
           'tawrite.cpp',
           'tcls.hpp',
           'tcls.cpp',
           'tdim.hpp',
           'tdim.cpp',
           'tlisto.hpp',
           'tlisto.cpp',
           'tnop.cpp',
           'tnop.hpp',
           'tread.cpp',
           'tread.hpp',
           'tstop.cpp',
           'tstop.hpp',
           'twrite.cpp',
           'twrite.hpp',
           'validity.hpp',
           'validity.cpp',
           'tlread.cpp',
           'tlread.hpp',
           'tlwrite.cpp',
           'tlwrite.hpp',
           'tloopend.hpp',
           'tloopend.cpp',
           'littable.cpp',
           'littable.hpp',
           'tifa.hpp',
           'tifa.cpp',
           'tgoto.cpp',
           'tgoto.hpp',
           'tif.hpp',
           'tif.cpp',
           'tloop.cpp',
           'tloop.hpp',
           'tsubp.hpp',
           'tsubp.cpp'
          ]
end

files = getListOfFilesToMake
count = 0
for f in files
  file = File.open(f,'r')
  count += file.read().split("\n").length()
  file.close
end

puts "Those files have " + count.to_s + " line in total"
