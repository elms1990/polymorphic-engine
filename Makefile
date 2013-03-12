######################### MAKEFILE ############################

# BASE DEFS #
LDFLAGS= -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
CXXFLAGS= -pedantic -Wall -ggdb

# SOURCE FILES #
SRC= $(wildcard src/*.cpp)
OBJS= $(SRC:.cpp=.o)
TESTS= tests/

# INCLUDE DIRECTORIES #
INCLUDE= -Iinclude

# LINUX #
LCXX= g++
LCXXFLAGS= $(CXXFLAGS)
LLDFLAGS= $(LDFLAGS)

# WIN32 #
W32CXX= i586-mingw32msvc-g++
W32LINKER= i586-mingw32msvc-ar
W32CXXFLAGS= $(CXXFLAGS)
W32LDFLAGS= -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

linux: linux-engine

linux-engine:
	@echo
	@echo \#\#\# COMPILING ENGINE FOR LINUX \#\#\#
	$(LCXX) $(SRC) -fPIC -shared -o libpolymorphic.so $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) 

install:
	cp libpolymorphic.so /usr/lib

w32: w32-engine

w32-engine: 
	@echo
	@echo \#\#\# COMPILING ENGINE FOR WIN32\#\#\#
	$(W32CXX) $(SRC) -c $(W32CXXFLAGS) $(INCLUDE) $(W32LDFLAGS)

clean:
	rm -f *.o
	rm -f *.so
	rm -f log.txt
