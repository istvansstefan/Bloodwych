#pragma once

class SDL2DViewport
{
public:
    SDL2DViewport(
        SDL_Renderer* renderer,
        int dungeonWidth,
        int dungeonHeight);

    void update();

    SDL_FPoint tileTopLeft(int x, int y) const;
    SDL_FPoint tileCenter(int x, int y) const;

private:
    void calculateOffset();

    SDL_Renderer* renderer_;

    float offsetX_;
    float offsetY_;

    const float mapWidth_;
    const float mapHeight_;
};
