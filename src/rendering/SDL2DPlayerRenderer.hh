#pragma once

#include <SDL3/SDL.h>

#include "../dungeon/Dungeon.hh"
#include "../player/Player.hh"

class SDL2DPlayerRenderer
{
public:
    explicit SDL2DPlayerRenderer(SDL_Renderer* renderer);

    void render(const Dungeon& dungeon, const Player& player);

private:
    SDL_Renderer* renderer_;
};
