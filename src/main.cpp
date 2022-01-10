#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_circle.h>
#include <iostream>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

typedef struct mouse {
    int x;
    int y;
} Mouse;

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow (
        "Raycasting",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (window == NULL)
    {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    bool run = true;

    SDL_Event event;

    SDL_Rect r;
    r.x = 50;
    r.y = 50;
    r.w = 20;
    r.h = 20;

    Mouse m;

    while (run)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
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
                    case SDLK_s:
                        r.y += 4;
                        break;
                    case SDLK_w:
                        r.y -= 4;
                        break;
                    case SDLK_d:
                        r.x += 4;
                        break;
                    case SDLK_a:
                        r.x -= 4;
                        break;
                    default:
                        break;
                }
            }

            if (event.type == SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&m.x, &m.y);
            }
        }
        SDL_RenderClear(renderer);

        // Rect
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillCircle(renderer, m.x, m.y, 10);

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderDrawRect(renderer, &r);

        // Line
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, 100, 100, m.x, m.y);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}