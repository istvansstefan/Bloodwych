#include "SDL2DDungeonRenderer.hh"
#include "SDL2DConstants.hh"

SDL2DDungeonRenderer::SDL2DDungeonRenderer(SDL_Renderer* renderer)
    : renderer_(renderer)
{
}

void SDL2DDungeonRenderer::render(const Dungeon& dungeon)
{
    int windowWidth = 0;
    int windowHeight = 0;

    SDL_GetRenderOutputSize(renderer_, &windowWidth, &windowHeight);

    // Clear the background.
    //SDL_SetRenderDrawColor(renderer_, 20, 20, 25, 255);
    //SDL_RenderClear(renderer_);


    // Center the dungeon in the window.
    const float mapWidth = dungeon.width() * SDL2D::TILE_SIZE;
    const float mapHeight = dungeon.height() * SDL2D::TILE_SIZE;

    const float offsetX = (windowWidth - mapWidth) / 2.0F;
    const float offsetY = (windowHeight - mapHeight) / 2.0F;

    for (int y = 0; y < dungeon.height(); ++y)
    {
        for (int x = 0; x < dungeon.width(); ++x)
        {
            const Tile& tile = dungeon.tileAt(x, y);

            SDL_FRect rect = {
                offsetX + x * SDL2D::TILE_SIZE,
                offsetY + y * SDL2D::TILE_SIZE,
                SDL2D::TILE_SIZE,
                SDL2D::TILE_SIZE
            };

            if (tile.type == TileType::Wall)
            {
                SDL_SetRenderDrawColor(renderer_, 90, 90, 100, 255);
            }
            else
            {
                SDL_SetRenderDrawColor(renderer_, 170, 155, 125, 255);
            }

            SDL_RenderFillRect(renderer_, &rect);

            // Draw tile boundaries.
            SDL_SetRenderDrawColor(renderer_, 40, 40, 45, 255);
            SDL_RenderRect(renderer_, &rect);
        }
    }

    //SDL_RenderPresent(renderer_);
}
