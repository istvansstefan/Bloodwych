#include "SDL2DDungeonRenderer.hh"
#include "SDL2DConstants.hh"

SDL2DDungeonRenderer::SDL2DDungeonRenderer(SDL_Renderer* renderer, const Dungeon& dungeon) :
    renderer_(renderer),
    dungeon_(dungeon),
    viewport_(renderer_, dungeon_.width(), dungeon_.height())
{
}

void SDL2DDungeonRenderer::render()
{
    // Clear the background.
    //SDL_SetRenderDrawColor(renderer_, 20, 20, 25, 255);
    //SDL_RenderClear(renderer_);

    for (int y = 0; y < dungeon_.height(); ++y)
    {
        for (int x = 0; x < dungeon_.width(); ++x)
        {
            const Tile& tile = dungeon_.tileAt(x, y);
            const SDL_FPoint tileCenter = viewport_.tileTopLeft(x, y);

            SDL_FRect rect = {
                tileCenter.x,
                tileCenter.y,
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
