SRC = ./src
BUILD = ./build
GCC = g++
PKG = `pkg-config --cflags --libs sdl2`

main:
	$(GCC) $(SRC)/main.cpp $(SRC)/ray.cpp $(SRC)/player.cpp -o $(BUILD)/main.out $(PKG)
