#pragma once

class SDL2DViewport
{
public:
    SDL2DViewport(
        SDL_Renderer* renderer,
        int dungeonWidth,
        int dungeonHeight);

    SDL_FPoint tileCenter(int x, int y) const;

private:
    float offsetX_;
    float offsetY_;
};
