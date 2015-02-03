COMPILEDFILES = table.o preprocess.o compiler.o
FILES = table preprocess compiler
TESTFILES = test.transy
TESTFLAGS = -n
TEMPFOLDER = temp
MAINFUNC = compiler.cpp
SOURCEDIR = src/
TESTDIR = tests/
PROGNAME = compiler

all: main

test: main
	for file in $(TESTFILES); do \
		./$(PROGNAME) $(TESTFLAGS) $(TESTDIR)$$file ; \
	done

main: compile
	cd $(SOURCEDIR) && \
	g++ $(COMPILEDFILES) -o $(PROGNAME)
	mv $(SOURCEDIR)$(PROGNAME) ./

compile:
	cd $(SOURCEDIR) && \
	for file in $(FILES) ; do \
		g++ $$file.cpp -c ; \
	done

clean:
	rm $(SOURCEDIR)*.o
