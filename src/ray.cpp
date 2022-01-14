#include <SDL2/SDL.h>
#include "ray.hpp"

Ray::Ray(float sx, float sy, float dx, float dy, float angle, int r)
{
    this->sx = sx;
    this->sy = sy;
    this->dx = dx;
    this->dy = dy;
    this->angle = angle;
    this->r = r;
}

void Ray::setX(float value)
{
    sx = value;
}

void Ray::setY(float value)
{
    sy = value;
}

void Ray::setDirX(float value)
{
    dx = sx + r * cos(-angle);
}

void Ray::setDirY(float value)
{
    dy = sy + r * sin(-angle);
}

void Ray::setAngle(int angle)
{
    this->angle = angle;
}

void Ray::Draw(SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderDrawLine(renderer, sx, sy, dx, dy);
}