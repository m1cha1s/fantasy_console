CC := gcc
CFLAGS := -O2 -Wall -Werror

CXX := g++
CXXFLAGS := $(CFLAGS)

INCLUDE := -I../luajit/src -I../raylib/src

LIBS := -L../luajit/src -lluajit 
LIBS += -L../raylib/src -lraylib

LIBS += -lm

EXE := fc

SRC := main.c gfx.c

OBJ := $(SRC:.c=.o)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $< -o $@ -c $(CFLAGS) $(INCLUDE)

%.o: %.cpp
	$(CXX) $< -o $@ -c $(CXXFLAGS) $(INCLUDE)

.PHONY: clean 

clean:
	rm -f $(EXE) $(OBJ)
