COMPILED_FILES = src/core.o src/earead.o src/eassignment.o src/eawrite.o src/ecdump.o src/ecls.o src/egoto.o src/eif.o src/eifa.o src/elisto.o src/eloop.o src/eloopend.o src/elread.o src/elwrite.o src/enop.o src/eread.o src/estop.o src/esubp.o src/ewrite.o src/executor.o src/littable.o src/preprocess.o src/symtable.o src/table.o src/taread.o src/tassignment.o src/tawrite.o src/tcdump.o src/tcls.o src/tdim.o src/tgoto.o src/tif.o src/tifa.o src/tlisto.o src/tloop.o src/tloopend.o src/tlread.o src/tlwrite.o src/tnop.o src/token.o src/tokenStack.o src/transducer.o src/tread.o src/tstop.o src/tsubp.o src/twrite.o src/validity.o
SOURCEDIR = src/
PROGNAME = compiler

all: compiler executor
compiler: $(COMPILED_FILES) 
	g++ $(COMPILED_FILES) $(SOURCEDIR)compiler.o -o $(PROGNAME)

executor: $(COMPILED_FILES) src/mainExecutor.o
	g++ $(COMPILED_FILES) $(SOURCEDIR)mainExecutor.o -o executor

src/mainExecutor.o: src/mainExecutor.cpp src/executor.hpp src/executor.o
	cd $(SOURCEDIR) && \
	g++ mainExecutor.cpp -c

src/compiler.o: src/compiler.cpp src/compiler.hpp src/executor.hpp src/preprocess.hpp src/validity.hpp src/symtable.hpp src/tread.hpp src/twrite.hpp src/tstop.hpp src/tcdump.hpp src/tcls.hpp src/tnop.hpp src/tlisto.hpp src/taread.hpp src/tawrite.hpp src/tdim.hpp src/core.hpp src/table.hpp src/tgoto.hpp src/littable.hpp src/tloopend.hpp src/tlwrite.hpp src/tlread.hpp src/tifa.hpp src/tif.hpp src/tloop.hpp src/tsubp.hpp src/tassignment.hpp src/executor.o src/preprocess.o src/validity.o src/symtable.o src/tread.o src/twrite.o src/tstop.o src/tcdump.o src/tcls.o src/tnop.o src/tlisto.o src/taread.o src/tawrite.o src/tdim.o src/core.o src/table.o src/tgoto.o src/littable.o src/tloopend.o src/tlwrite.o src/tlread.o src/tifa.o src/tif.o src/tloop.o src/tsubp.o src/tassignment.o
	cd $(SOURCEDIR) && \
	g++ compiler.cpp -c

src/core.o: src/core.cpp src/core.hpp 
	cd $(SOURCEDIR) && \
	g++ core.cpp -c

src/earead.o: src/earead.cpp src/earead.hpp src/validity.hpp src/core.hpp src/validity.o src/core.o
	cd $(SOURCEDIR) && \
	g++ earead.cpp -c

src/eassignment.o: src/eassignment.cpp src/eassignment.hpp src/validity.hpp src/generalstack.hpp src/core.hpp src/validity.o src/core.o
	cd $(SOURCEDIR) && \
	g++ eassignment.cpp -c

src/eawrite.o: src/eawrite.cpp src/eawrite.hpp src/validity.hpp src/core.hpp src/validity.o src/core.o
	cd $(SOURCEDIR) && \
	g++ eawrite.cpp -c

src/ecdump.o: src/ecdump.cpp src/ecdump.hpp src/validity.hpp src/core.hpp src/validity.o src/core.o
	cd $(SOURCEDIR) && \
	g++ ecdump.cpp -c

src/ecls.o: src/ecls.cpp src/ecls.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ ecls.cpp -c

src/egoto.o: src/egoto.cpp src/egoto.hpp src/validity.hpp src/core.hpp src/validity.o src/core.o
	cd $(SOURCEDIR) && \
	g++ egoto.cpp -c

src/eif.o: src/eif.cpp src/eif.hpp src/validity.hpp src/core.hpp src/validity.o src/core.o
	cd $(SOURCEDIR) && \
	g++ eif.cpp -c

src/eifa.o: src/eifa.cpp src/eifa.hpp src/validity.hpp src/core.hpp src/validity.o src/core.o
	cd $(SOURCEDIR) && \
	g++ eifa.cpp -c

src/elisto.o: src/elisto.cpp src/elisto.hpp src/validity.hpp src/executor.hpp src/validity.o src/executor.o
	cd $(SOURCEDIR) && \
	g++ elisto.cpp -c

src/eloop.o: src/eloop.cpp src/eloop.hpp src/validity.hpp src/core.hpp src/validity.o src/core.o
	cd $(SOURCEDIR) && \
	g++ eloop.cpp -c

src/eloopend.o: src/eloopend.cpp src/eloopend.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ eloopend.cpp -c

src/elread.o: src/elread.cpp src/elread.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ elread.cpp -c

src/elwrite.o: src/elwrite.cpp src/elwrite.hpp src/validity.hpp src/core.hpp src/validity.o src/core.o
	cd $(SOURCEDIR) && \
	g++ elwrite.cpp -c

src/enop.o: src/enop.cpp src/enop.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ enop.cpp -c

src/eread.o: src/eread.cpp src/eread.hpp src/validity.hpp src/core.hpp src/validity.o src/core.o
	cd $(SOURCEDIR) && \
	g++ eread.cpp -c

src/estop.o: src/estop.cpp src/estop.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ estop.cpp -c

src/esubp.o: src/esubp.cpp src/esubp.hpp src/validity.hpp src/core.hpp src/validity.o src/core.o
	cd $(SOURCEDIR) && \
	g++ esubp.cpp -c

src/ewrite.o: src/ewrite.cpp src/ewrite.hpp src/validity.hpp src/core.hpp src/validity.o src/core.o
	cd $(SOURCEDIR) && \
	g++ ewrite.cpp -c

src/executor.o: src/executor.cpp src/validity.hpp src/generalstack.hpp src/table.hpp src/eread.hpp src/ewrite.hpp src/estop.hpp src/ecdump.hpp src/elisto.hpp src/enop.hpp src/egoto.hpp src/eifa.hpp src/earead.hpp src/eawrite.hpp src/eloop.hpp src/eloopend.hpp src/elread.hpp src/elwrite.hpp src/eif.hpp src/ecls.hpp src/esubp.hpp src/eassignment.hpp src/validity.o src/table.o src/eread.o src/ewrite.o src/estop.o src/ecdump.o src/elisto.o src/enop.o src/egoto.o src/eifa.o src/earead.o src/eawrite.o src/eloop.o src/eloopend.o src/elread.o src/elwrite.o src/eif.o src/ecls.o src/esubp.o src/eassignment.o
	cd $(SOURCEDIR) && \
	g++ executor.cpp -c

src/littable.o: src/littable.cpp src/littable.hpp src/table.hpp src/table.o
	cd $(SOURCEDIR) && \
	g++ littable.cpp -c

src/preprocess.o: src/preprocess.cpp src/preprocess.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ preprocess.cpp -c

src/symtable.o: src/symtable.cpp src/symtable.hpp src/validity.hpp src/table.hpp src/core.hpp src/validity.o src/table.o src/core.o
	cd $(SOURCEDIR) && \
	g++ symtable.cpp -c

src/table.o: src/table.cpp src/table.hpp 
	cd $(SOURCEDIR) && \
	g++ table.cpp -c

src/taread.o: src/taread.cpp src/taread.hpp src/validity.hpp src/symtable.hpp src/validity.o src/symtable.o
	cd $(SOURCEDIR) && \
	g++ taread.cpp -c

src/tassignment.o: src/tassignment.cpp src/validity.hpp src/tassignment.hpp src/token.hpp src/tokenStack.hpp src/transducer.hpp src/symtable.hpp src/validity.o src/token.o src/tokenStack.o src/transducer.o src/symtable.o
	cd $(SOURCEDIR) && \
	g++ tassignment.cpp -c

src/tawrite.o: src/tawrite.cpp src/tawrite.hpp src/validity.hpp src/symtable.hpp src/validity.o src/symtable.o
	cd $(SOURCEDIR) && \
	g++ tawrite.cpp -c

src/tcdump.o: src/tcdump.cpp src/tcdump.hpp src/validity.hpp src/symtable.hpp src/validity.o src/symtable.o
	cd $(SOURCEDIR) && \
	g++ tcdump.cpp -c

src/tcls.o: src/tcls.cpp src/tcls.hpp src/validity.hpp src/symtable.hpp src/validity.o src/symtable.o
	cd $(SOURCEDIR) && \
	g++ tcls.cpp -c

src/tdim.o: src/tdim.cpp src/tdim.hpp src/validity.hpp src/symtable.hpp src/validity.o src/symtable.o
	cd $(SOURCEDIR) && \
	g++ tdim.cpp -c

src/tgoto.o: src/tgoto.cpp src/tgoto.hpp src/validity.hpp src/table.hpp src/validity.o src/table.o
	cd $(SOURCEDIR) && \
	g++ tgoto.cpp -c

src/tif.o: src/tif.cpp src/tif.hpp src/validity.hpp src/table.hpp src/symtable.hpp src/validity.o src/table.o src/symtable.o
	cd $(SOURCEDIR) && \
	g++ tif.cpp -c

src/tifa.o: src/tifa.cpp src/tifa.hpp src/validity.hpp src/table.hpp src/symtable.hpp src/validity.o src/table.o src/symtable.o
	cd $(SOURCEDIR) && \
	g++ tifa.cpp -c

src/tlisto.o: src/tlisto.cpp src/tlisto.hpp src/validity.hpp src/symtable.hpp src/validity.o src/symtable.o
	cd $(SOURCEDIR) && \
	g++ tlisto.cpp -c

src/tloop.o: src/tloop.cpp src/tloop.hpp src/validity.hpp src/symtable.hpp src/validity.o src/symtable.o
	cd $(SOURCEDIR) && \
	g++ tloop.cpp -c

src/tloopend.o: src/tloopend.cpp src/tloopend.hpp src/validity.hpp src/validity.o
	cd $(SOURCEDIR) && \
	g++ tloopend.cpp -c

src/tlread.o: src/tlread.cpp src/tlread.hpp src/validity.hpp src/littable.hpp src/validity.o src/littable.o
	cd $(SOURCEDIR) && \
	g++ tlread.cpp -c

src/tlwrite.o: src/tlwrite.cpp src/tlwrite.hpp src/validity.hpp src/littable.hpp src/validity.o src/littable.o
	cd $(SOURCEDIR) && \
	g++ tlwrite.cpp -c

src/tnop.o: src/tnop.cpp src/tnop.hpp src/validity.hpp src/symtable.hpp src/validity.o src/symtable.o
	cd $(SOURCEDIR) && \
	g++ tnop.cpp -c

src/token.o: src/token.cpp src/token.hpp 
	cd $(SOURCEDIR) && \
	g++ token.cpp -c

src/tokenStack.o: src/tokenStack.cpp src/tokenStack.hpp src/token.hpp src/token.o
	cd $(SOURCEDIR) && \
	g++ tokenStack.cpp -c

src/transducer.o: src/transducer.cpp src/transducer.hpp src/token.hpp src/token.o
	cd $(SOURCEDIR) && \
	g++ transducer.cpp -c

src/tread.o: src/tread.cpp src/tread.hpp src/validity.hpp src/symtable.hpp src/validity.o src/symtable.o
	cd $(SOURCEDIR) && \
	g++ tread.cpp -c

src/tstop.o: src/tstop.cpp src/tstop.hpp src/validity.hpp src/symtable.hpp src/validity.o src/symtable.o
	cd $(SOURCEDIR) && \
	g++ tstop.cpp -c

src/tsubp.o: src/tsubp.cpp src/tsubp.hpp src/validity.hpp src/symtable.hpp src/validity.o src/symtable.o
	cd $(SOURCEDIR) && \
	g++ tsubp.cpp -c

src/twrite.o: src/twrite.cpp src/twrite.hpp src/validity.hpp src/symtable.hpp src/validity.o src/symtable.o
	cd $(SOURCEDIR) && \
	g++ twrite.cpp -c

src/validity.o: src/validity.cpp src/validity.hpp 
	cd $(SOURCEDIR) && \
	g++ validity.cpp -c

clean:
	rm $(SOURCEDIR)*.o
