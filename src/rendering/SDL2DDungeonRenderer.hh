#pragma once

#include <SDL3/SDL.h>

#include "../dungeon/Dungeon.hh"
#include "SDL2DViewport.hh"

class SDL2DDungeonRenderer
{
public:
    explicit SDL2DDungeonRenderer(SDL_Renderer* renderer, const SDL2DViewport& viewport, const Dungeon& dungeon);

    void render();

private:
    SDL_Renderer* renderer_;
    const Dungeon& dungeon_;
    const SDL2DViewport& viewport_;
};
