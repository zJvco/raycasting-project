#include <SDL2/SDL.h>
#include "player.hpp"

Player::Player(int x, int y, int w, int h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

void Player::draw(SDL_Renderer *renderer)
{
    // Player Rect
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderDrawLine(renderer, rect.x+rect.w/2, rect.y+rect.h/2, rect.x+dx, rect.y+dy);
}