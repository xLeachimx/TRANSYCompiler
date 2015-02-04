COMPILEDFILES = table.o preprocess.o compiler.o symtable.o tread.o tstop.o twrite.o validity.o
HEADERFILES = table.hpp preprocess.hpp compiler.hpp symtable.hpp tread.hpp tstop.hpp twrite.hpp validity.hpp
SOURCEFILES = table.cpp preprocess.cpp compiler.cpp symtable.cpp tread.cpp tstop.cpp twrite.cpp validity.cpp
TEMPFOLDER = temp
MAINFUNC = compiler.cpp
SOURCEDIR = src/
PROGNAME = compiler

all: main

main: compile
	cd $(SOURCEDIR) && \
	g++ $(COMPILEDFILES) -o $(PROGNAME)
	mv $(SOURCEDIR)$(PROGNAME) ./

compile:
	cd $(SOURCEDIR) && \
	for file in $(SOURCEFILES) ; do \
		g++ $$file -c ; \
	done

clean:
	rm $(SOURCEDIR)*.o
