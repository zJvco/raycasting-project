#include <SDL2/SDL.h>

class Player
{
    public:
        int x, y, angle = 0;
        int w, h;
        double dx, dy;

        Player(int x, int y, int w, int h);
        void draw(SDL_Renderer *renderer);
};