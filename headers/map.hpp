#include <SDL2/SDL.h>

int mapX = 10, mapY = 10;
int tileSizeX = WIDTH / mapX, tileSizeY = HEIGHT / mapY;

int map[] =
{
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

void drawMap2D(SDL_Renderer *renderer, int *m)
{
    for (int i = 0; i < mapX; i++)
    {
        for (int j = 0; j < mapY; j++)
        {
            if (m[i*mapX+j] == 1)
            {
                SDL_Rect tile;
                tile.x = j * tileSizeX;
                tile.y = i * tileSizeY;
                tile.w = tileSizeX;
                tile.h = tileSizeY;

                SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawRect(renderer, &tile);
            }
        }
    }
}