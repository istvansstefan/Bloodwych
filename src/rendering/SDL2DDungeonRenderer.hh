#pragma once

#include <SDL3/SDL.h>

#include "../dungeon/Dungeon.hh"

class SDL2DDungeonRenderer
{
public:
    explicit SDL2DDungeonRenderer(SDL_Renderer* renderer);

    void render(const Dungeon& dungeon);

private:
    SDL_Renderer* renderer_;
};
