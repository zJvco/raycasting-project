#include <SDL2/SDL.h>

class Player
{
    private:
    public:
        int x, y, dx, dy, angle = 0;
        int w, h;

        Player(int x, int y, int w, int h);
        void draw(SDL_Renderer *renderer);
};