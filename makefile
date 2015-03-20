COMPILED_FILES = src/core.o src/littable.o src/preprocess.o src/symtable.o src/table.o src/taread.o src/tawrite.o src/tcdump.o src/tcls.o src/tdim.o src/tgoto.o src/tif.o src/tifa.o src/tlisto.o src/tloop.o src/tloopend.o src/tlread.o src/tlwrite.o src/tnop.o src/tread.o src/tstop.o src/tsubp.o src/twrite.o src/validity.o
SOURCEDIR = src/
PROGNAME = compiler

all: main
main: $(COMPILED_FILES) 
	g++ src/compiler.cpp $(COMPILED_FILES) -o $(PROGNAME)

src/core.o: src/core.cpp src/core.hpp 
	cd $(SOURCEDIR) && \
	g++ core.cpp -c

src/littable.o: src/littable.cpp src/littable.hpp 
	cd $(SOURCEDIR) && \
	g++ littable.cpp -c

src/preprocess.o: src/preprocess.cpp src/preprocess.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ preprocess.cpp -c

src/symtable.o: src/symtable.cpp src/symtable.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ symtable.cpp -c

src/table.o: src/table.cpp src/table.hpp 
	cd $(SOURCEDIR) && \
	g++ table.cpp -c

src/taread.o: src/taread.cpp src/taread.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ taread.cpp -c

src/tawrite.o: src/tawrite.cpp src/tawrite.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ tawrite.cpp -c

src/tcdump.o: src/tcdump.cpp src/tcdump.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ tcdump.cpp -c

src/tcls.o: src/tcls.cpp src/tcls.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ tcls.cpp -c

src/tdim.o: src/tdim.cpp src/tdim.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ tdim.cpp -c

src/tgoto.o: src/tgoto.cpp src/tgoto.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ tgoto.cpp -c

src/tif.o: src/tif.cpp src/tif.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ tif.cpp -c

src/tifa.o: src/tifa.cpp src/tifa.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ tifa.cpp -c

src/tlisto.o: src/tlisto.cpp src/tlisto.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ tlisto.cpp -c

src/tloop.o: src/tloop.cpp src/tloop.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ tloop.cpp -c

src/tloopend.o: src/tloopend.cpp src/tloopend.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ tloopend.cpp -c

src/tlread.o: src/tlread.cpp src/tlread.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ tlread.cpp -c

src/tlwrite.o: src/tlwrite.cpp src/tlwrite.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ tlwrite.cpp -c

src/tnop.o: src/tnop.cpp src/tnop.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ tnop.cpp -c

src/tread.o: src/tread.cpp src/tread.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ tread.cpp -c

src/tstop.o: src/tstop.cpp src/tstop.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ tstop.cpp -c

src/tsubp.o: src/tsubp.cpp src/tsubp.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ tsubp.cpp -c

src/twrite.o: src/twrite.cpp src/twrite.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ twrite.cpp -c

src/validity.o: src/validity.cpp src/validity.hpp 
	cd $(SOURCEDIR) && \
	g++ validity.cpp -c

clean:
	rm $(SOURCEDIR)*.o
