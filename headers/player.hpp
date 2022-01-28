#include <SDL2/SDL.h>

#include "../headers/utils.hpp"

class Player
{
    public:
        int x, y, angle = 0;
        int w, h;
        double speed;
        double dx = cos(get_radians(angle)), dy = sin(get_radians(angle));

        Player(int x, int y, int w, int h, double speed);
        void draw(SDL_Renderer *renderer);
};