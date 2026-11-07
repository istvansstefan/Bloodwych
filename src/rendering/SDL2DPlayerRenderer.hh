#pragma once

#include <SDL3/SDL.h>

#include "../dungeon/Dungeon.hh"
#include "../player/Player.hh"
#include "SDL2DViewport.hh"

class SDL2DPlayerRenderer
{
public:
    explicit SDL2DPlayerRenderer(SDL_Renderer* renderer, const Dungeon& dungeon);

    void render(const Player& player);

private:
    SDL_Renderer* renderer_;
    const Dungeon& dungeon_;
    SDL2DViewport viewport_;
};
