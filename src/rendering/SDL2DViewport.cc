#include <SDL3/SDL.h>

#include "SDL2DViewport.hh"
#include "SDL2DConstants.hh"

SDL2DViewport::SDL2DViewport(SDL_Renderer* renderer, int dungeonWidth, int dungeonHeight)
{
    int windowWidth = 0;
    int windowHeight = 0;

    SDL_GetRenderOutputSize(renderer, &windowWidth, &windowHeight);

    const float mapWidth = dungeonWidth * SDL2D::TILE_SIZE;
    const float mapHeight = dungeonHeight * SDL2D::TILE_SIZE;

    offsetX_ = (windowWidth - mapWidth) / 2.0F;
    offsetY_ = (windowHeight - mapHeight) / 2.0F;
}

SDL_FPoint SDL2DViewport::tileCenter(int x, int y) const
{
    float tileCenterX = offsetX_ + x * SDL2D::TILE_SIZE;
    float tileCenterY = offsetY_ + y * SDL2D::TILE_SIZE;
    
    return SDL_FPoint(tileCenterX, tileCenterY);
}

