#include <SDL2/SDL.h>

class Player
{
    private:
    public:
        int x, y, dx, dy, angle = 0;

        Player(int x, int y, float dx, float dy);
        void draw(SDL_Renderer *renderer, SDL_Rect *rect);
};