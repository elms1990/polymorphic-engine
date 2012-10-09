######################### MAKEFILE ############################

# BASE DEFS #
LDFLAGS= -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf `sdl-config --cflags --libs` -lGL
CXXFLAGS= -pedantic -Wall -ggdb
LIBNAME=polymorphic-engine.a

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

linux: linux-engine

linux-engine:
	@echo
	@echo \#\#\# COMPILING ENGINE FOR LINUX \#\#\#
	$(LCXX) $(SRC) -c $(CXXFLAGS) $(INCLUDE) $(LDFLAGS)
	$(LLINKER) cq $(LIBNAME) *.o

w32: w32-engine

w32-engine: 
	@echo
	@echo \#\#\# COMPILING ENGINE FOR WIN32\#\#\#
	$(W32CXX) $(SRC) -c $(W32CXXFLAGS) $(INCLUDE) $(W32LDFLAGS)
	$(W32LINKER) cq $(LIBNAME) *.o

clean:
	rm -f *.o
	rm -f *.a
	rm -f log.txt
