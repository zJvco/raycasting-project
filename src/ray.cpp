#include <SDL2/SDL.h>
#include "ray.hpp"
#include "utils.hpp"

Ray::Ray(double sx, double sy, double dx, double dy, double angle, int r)
{
    this->sx = sx;
    this->sy = sy;
    this->dx = dx;
    this->dy = dy;
    this->angle = angle;
    this->r = r;
}

void Ray::setX(double value)
{
    sx = value;
}

void Ray::setY(double value)
{
    sy = value;
}

void Ray::setDirX(double value)
{
    dx = sx + r * cos(-(angle + get_radians(value)));
}

void Ray::setDirY(double value)
{
    dy = sy + r * sin(-(angle + get_radians(value)));
}

void Ray::Draw(SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderDrawLine(renderer, sx, sy, dx, dy);
}