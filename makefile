COMPILEDFILES = table.o preprocess.o compiler.o symtable.0 tread.o tstop.o twrite.o validity.o
HEADERFILES = table.hpp preprocess.hpp compiler.hpp symtable.hpp tread.hpp tstop.hpp twrite.hpp validity.hpp
SOURCEFILES = table.cpp preporcess.cpp compiler.cpp symtable.cpp tread.cpp tstop.cpp twrite.cpp validity.cpp
TEMPFOLDER = temp
MAINFUNC = compiler.cpp
SOURCEDIR = src/
PROGNAME = compiler

all: main

main: COMPILEDFILES
	cd $(SOURCEDIR) && \
	g++ $(COMPILEDFILES) -o $(PROGNAME)
	mv $(SOURCEDIR)$(PROGNAME) ./

compile: HEADERFILES
	cd $(SOURCEDIR) && \
	for file in $(FILES) ; do \
		g++ $$file.cpp -c ; \
	done

clean:
	rm $(SOURCEDIR)*.o
