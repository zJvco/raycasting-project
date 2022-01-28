#include <SDL2/SDL.h>
#include "../headers/player.hpp"

Player::Player(int x, int y, int w, int h, double speed)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->speed = speed;
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
}