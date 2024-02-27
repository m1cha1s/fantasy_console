CC := gcc
CFLAGS := -O2 -Wall -Werror

CXX := g++
CXXFLAGS := $(CFLAGS)

INCLUDE := -I./luajit/src
LIBS := -L./luajit/src -lluajit -lm

EXE := fc
OBJ := main.o

fc: $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $< -o $@ -c $(CFLAGS) $(INCLUDE)

%.o: %.cpp
	$(CXX) $< -o $@ -c $(CXXFLAGS) $(INCLUDE)

.PHONY: all clean_all clean clean_deps deps luajit submodules

all:
	make -C . deps -j
	make -C . -j

deps: luajit
	
luajit: submodules
	-patch -N -r- ./luajit/src/Makefile patches/luajitMk.patch
	make -C luajit -j

clean_all: clean clean_deps

clean:
	rm -f $(EXE) $(OBJ)

clean_deps:
	-patch -R ./luajit/src/Makefile patches/luajitMk.patch
	make -C luajit clean

submodules:
	git submodule update --init
