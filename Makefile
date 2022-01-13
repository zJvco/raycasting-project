SRC = ./src
GCC = g++
PKG = `pkg-config --cflags --libs sdl2`

game:
	$(GCC) $(SRC)/game.cpp $(SRC)/ray.cpp -o $(SRC)/game.out $(PKG)
