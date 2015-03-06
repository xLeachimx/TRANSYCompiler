COMPILEDFILES = table.o preprocess.o compiler.o symtable.o tread.o tstop.o twrite.o validity.o tlisto.o tnop.o tcls.o tcdump.o taread.o tawrite.o tdim.o core.o lread.o littable.o tgoto.o tlwrite.o tloopend.o tifa.o tif.o tloop.o tsubp.o
SOURCEFILES = $(COMPILEDFILES:.o=.cpp)
TEMPFOLDER = temp
MAINFUNC = compiler.cpp
SOURCEDIR = src/
COMPFLAGS = #-std=c++11
PROGNAME = compiler

all: main

main: $(SOURCEFILES)
	cd $(SOURCEDIR) && \
	g++ $(COMPFLAGS) $(COMPILEDFILES) -o $(PROGNAME)
	mv $(SOURCEDIR)$(PROGNAME) ./

$(SOURCEFILES):
	cd $(SOURCEDIR) && \
	g++ $@ -c $(COMPFLAGS)

clean:
	rm $(SOURCEDIR)*.o
