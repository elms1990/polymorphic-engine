######################### MAKEFILE ############################

# BASE DEFS #
VERSION=0.0.1
LDFLAGS= -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf `sdl-config --cflags --libs` -lGL
CXXFLAGS= -pedantic -Wall -ggdb
LIBNAME=polymorphic-engine-$(VERSION).a
export LIBNAME

# SOURCE FILES #
SRC= $(wildcard src/*.cpp)
OBJS= $(SRC:.cpp=.o)
TESTS= tests/

# INCLUDE DIRECTORIES #
INCLUDE= -Iinclude

# LINUX #
LCXX= g++
LLINKER= ar
LCXXFLAGS= $(CXXFLAGS)
LLDFLAGS= $(LDFLAGS)

# WIN32 #
W32CXX= i586-mingw32msvc-g++
W32LINKER= i586-mingw32msvc-ar
W32CXXFLAGS= $(CXXFLAGS)
W32LDFLAGS= -lmingw32 -lSDLmain -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lGL

linux: linux-engine linux-tests docs

linux-engine:
	@echo
	@echo \#\#\# COMPILING ENGINE FOR LINUX \#\#\#
	$(LCXX) $(SRC) -c $(CXXFLAGS) $(INCLUDE) $(LDFLAGS)
	$(LLINKER) cq $(LIBNAME) *.o

linux-tests:
	cd $(TESTS); \
	for tt in *; do \
		cd $$tt; \
		make linux; \
		cd ..; \
	done

w32: w32-engine w32-tests docs

w32-engine: 
	@echo
	@echo \#\#\# COMPILING ENGINE FOR WIN32\#\#\#
	$(W32CXX) $(SRC) -c $(W32CXXFLAGS) $(INCLUDE) $(W32LDFLAGS)
	$(W32LINKER) cq $(LIBNAME) *.o

w32-tests:
	cd $(TESTS); \
	for tt in *; do \
		cd $$tt; \
		make w32; \
		cd ..; \
	done

docs:
	@echo
	@echo \#\#\# COMPILING LATEX DOCUMENTATION \#\#\#
	cd doc/; pdflatex doc.tex

clean:
	rm -f *.o
	rm -f *.a
	rm -f log.txt
	cd doc/; rm -f doc.log doc.aux doc.pdf
	cd $(TESTS); \
	for proj in *; do \
		cd $$proj; \
		make clean; \
		cd ..; \
	done
