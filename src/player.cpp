#include <SDL2/SDL.h>
#include "player.hpp"

Player::Player(int x, int y, float dx, float dy)
{
    this->x = x;
    this->y = y;
    this->dx = dx;
    this->dy = dy;
}

void Player::draw(SDL_Renderer *renderer, SDL_Rect *rect)
{
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, rect);

    // SDL_RenderDrawLine(renderer, rect->x+rect->w/2, rect->y+rect->h/2, rect->x+dx, rect->y+dy);
}