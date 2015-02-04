COMPILEDFILES = table.o preprocess.o compiler.o symtable.o tread.o tstop.o twrite.o validity.o
SOURCEFILES = $(COMPILEDFILES:.o=.cpp)
TEMPFOLDER = temp
MAINFUNC = compiler.cpp
SOURCEDIR = src/
PROGNAME = compiler

all: main

main: $(SOURCEFILES)
	cd $(SOURCEDIR) && \
	g++ $(COMPILEDFILES) -o $(PROGNAME)
	mv $(SOURCEDIR)$(PROGNAME) ./

$(SOURCEFILES):
	cd $(SOURCEDIR) && \
	g++ $@ -c

clean:
	rm $(SOURCEDIR)*.o
