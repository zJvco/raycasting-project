#include <SDL2/SDL.h>

class Ray
{
    public:
        int r;
        double sx, sy, dx, dy, angle;

        Ray(double sx, double sy, double dx, double dy, double angle, int r);
        void Draw(SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
};
