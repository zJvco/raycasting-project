SRC = ./src
GCC = g++
PKG = `pkg-config --cflags --libs sdl2`

main:
	$(GCC) $(SRC)/main.cpp -o $(SRC)/main.out $(PKG)
