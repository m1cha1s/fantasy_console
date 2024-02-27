CC := gcc
CFLAGS := -O2 -Wall -Werror

CXX := g++
CXXFLAGS := $(CFLAGS)

INCLUDE := -I./luajit/src -I./raylib/src

LIBS := -L./luajit/src -lluajit 
LIBS += -L./raylib/src -lraylib

LIBS += -lm

EXE := fc
OBJ := main.o

fc: $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $< -o $@ -c $(CFLAGS) $(INCLUDE)

%.o: %.cpp
	$(CXX) $< -o $@ -c $(CXXFLAGS) $(INCLUDE)

.PHONY: all clean_all clean clean_deps deps luajit raylib submodules

all:
	make -C . deps -j
	make -C . -j

deps: luajit raylib

raylib: submodules
	PLATFORM=PLATFORM_DESKTOP make -C raylib/src -j
	
luajit: submodules
	-patch -N -r- ./luajit/src/Makefile patches/luajitMk.patch
	make -C luajit -j

clean_all: clean clean_deps

clean:
	rm -f $(EXE) $(OBJ)

clean_deps:
	-patch -R ./luajit/src/Makefile patches/luajitMk.patch
	make -C luajit clean
	make -C raylib/src clean

submodules:
	git submodule update --init
