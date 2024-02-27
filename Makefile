.PHONY: all clean luajit raylib submodules

all: submodules
	# Building raylib
	PLATFORM=PLATFORM_DESKTOP make -C raylib/src -j
	# Building luajit
	-patch -N -r- ./luajit/src/Makefile patches/luajitMk.patch
	make -C luajit -j
	# Building the project
	make -C src -j

clean:
	# Clean the project
	make -C src clean
	# Clean luajit
	-patch -R ./luajit/src/Makefile patches/luajitMk.patch
	make -C luajit clean
	# Clean raylib
	make -C raylib/src clean

submodules:
	git submodule update --init
