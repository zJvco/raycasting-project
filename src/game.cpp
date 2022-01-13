#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_circle.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <time.h>

#include "game.hpp"
#include "ray.hpp"
#include "utils.hpp"
#include "map.hpp"

typedef struct player
{
    int x = WIDTH / 2;
    int y = HEIGHT / 2;
    int angle;
    int dx = cos(angle) * 5;
    int dy = sin(angle) * 5;
} Player;

int main(int argc, char* argv[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;

    bool run = true;

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        std::cout << "Failed to initialize SDL %s\n" << SDL_GetError();

    window = SDL_CreateWindow (
        "Raycasting",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (window == NULL)
    {
        std::cout << "Could not create window: %s\n" << SDL_GetError();
        return 1;
    }

    if (FULLSCREEN)
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer == NULL)
    {
        std::cout << "Could not create renderer: %s\n" << SDL_GetError();
        return 1;
    }

    SDL_Event event;

    Player p;

    // Criando os raios (objetos)
    std::vector<Ray> rays;

    for (int a = 0; a < WIDTH; a++)
    {
        Ray ray(p.x, p.y, 0, 0, get_radians(a), 1000);
        rays.push_back(ray);
    }

    // Objeto do chão
    SDL_Rect floor;
    floor.x = 0;
    floor.y = HEIGHT / 2;
    floor.w = WIDTH;
    floor.h = HEIGHT;

    // Player Rect
    SDL_Rect pr;
    pr.w = 15;
    pr.h = 15;

    // Loop principal
    while (run)
    {
        // Começando a contar o tempo que leva para realizar as ações abaixo
        frameStart = SDL_GetTicks();

        // Fundo do céu
        SDL_SetRenderDrawColor(renderer, 135, 206, 235, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        
        // Fundo do chão
        SDL_SetRenderDrawColor(renderer, 175, 175, 175, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &floor);

        // Loop de eventos
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                run = false;
                break;
            }

            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_w:
                        p.x += p.dx;
                        p.y += p.dy;
                        break;
                    case SDLK_s:
                        p.x -= p.dx;
                        p.y -= p.dy;
                        break;
                    case SDLK_a:
                        p.angle -= 5;
                        if (p.angle < 0)
                        {
                            p.angle += 360;
                        }
                        p.dx = cos(get_radians(p.angle)) * 5;
                        p.dy = sin(get_radians(p.angle)) * 5;
                        break;
                    case SDLK_d:
                        p.angle += 5;
                        if (p.angle > 359)
                        {
                            p.angle -= 360;
                        }
                        p.dx = cos(get_radians(p.angle)) * 5;
                        p.dy = sin(get_radians(p.angle)) * 5;
                        break;
                    default:
                        break;
                }
            }
        }

        pr.x = p.x;
        pr.y = p.y;

        drawMap2D(renderer, map);

        // for (Ray& ray : rays)
        // {
        //     ray.setX(p.x);
        //     ray.setY(p.y);
        //     ray.setDirX();
        //     ray.setDirY();
            
        //     ray.Draw(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        // }

        // Player
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &pr);

        SDL_RenderDrawLine(renderer, pr.x, pr.y, pr.x+p.dx*20, pr.y+p.dy*20);
        
        SDL_RenderPresent(renderer);

        // Tempo final do processo realizado acima
        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();
    return 0;
}