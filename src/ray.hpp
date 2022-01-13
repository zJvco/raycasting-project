#include <SDL2/SDL.h>

class Ray
{
    private:
        int r;
        float sx, sy, dx, dy, angle;
    public:
        Ray(float sx, float sy, float dx, float dy, float angle, int r);
        void setX(float value);
        void setY(float value);
        void setDirX();
        void setDirY();
        void Draw(SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
};
