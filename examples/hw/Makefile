######################### MAKEFILE ############################

# BASE DEFS #
LDFLAGS= -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf `sdl-config --cflags --libs` -lGL
CXXFLAGS= -pedantic -Wall -ggdb

# SOURCE FILES #
SRC= $(wildcard src/*.cpp)
TESTS= tests/

# INCLUDE DIRECTORIES #
INCLUDE= -Iinclude -I../../include

# LINUX #
LCXX= g++
LCXXFLAGS= $(CXXFLAGS)
LLDFLAGS= $(LDFLAGS)

# WIN32 #
W32CXX= i586-mingw32msvc-g++
W32CXXFLAGS= $(CXXFLAGS)
W32LDFLAGS= -lmingw32 -lSDLmain -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -Wl,-subsystem,windows -lopengl32

linux:
	@echo
	@echo \#\#\# COMPILING HELLO WORLD FOR LINUX \#\#\#
	$(LCXX) $(SRC) -o hw.o $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -lpolymorphic

w32: 
	@echo
	@echo \#\#\# COMPILING HELLO WORLD FOR W32 \#\#\#
	$(W32CXX) $(SRC) ../../$(LIBNAME) hw.exe $(W32CXXFLAGS) $(INCLUDE) $(W32LDFLAGS)

clean:
	rm -f *.o
	rm -f *.a
	rm -f log.txt
	rm -f *.exe
