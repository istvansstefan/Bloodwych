#include "SDL2DPlayerRenderer.hh"
#include "SDL2DConstants.hh"

SDL2DPlayerRenderer::SDL2DPlayerRenderer(SDL_Renderer* renderer)
    : renderer_(renderer)
{
}

void SDL2DPlayerRenderer::render(
    const Dungeon& dungeon,
    const Player& player)
{
    int windowWidth = 0;
    int windowHeight = 0;

    SDL_GetRenderOutputSize(renderer_, &windowWidth, &windowHeight);

    // Center the dungeon in the window.
    const float mapWidth = dungeon.width() * SDL2D::TILE_SIZE;
    const float mapHeight = dungeon.height() * SDL2D::TILE_SIZE;

    const float offsetX = (windowWidth - mapWidth) / 2.0F;
    const float offsetY = (windowHeight - mapHeight) / 2.0F;

    // Calculate player position in screen coordinates.
    const float centerX =
        offsetX + (player.x() + 0.5F) * SDL2D::TILE_SIZE;

    const float centerY =
        offsetY + (player.y() + 0.5F) * SDL2D::TILE_SIZE;

    // Draw player marker.
    SDL_SetRenderDrawColor(renderer_, 220, 60, 60, 255);

    SDL_FRect playerRect = {
        centerX - SDL2D::PLAYER_SIZE / 2.0F,
        centerY - SDL2D::PLAYER_SIZE / 2.0F,
        SDL2D::PLAYER_SIZE,
        SDL2D::PLAYER_SIZE
    };

    SDL_RenderFillRect(renderer_, &playerRect);

    // Determine facing direction.
    float directionX = 0.0F;
    float directionY = 0.0F;

    switch (player.direction())
    {
        case Direction::North:
            directionY = -1.0F;
            break;

        case Direction::East:
            directionX = 1.0F;
            break;

        case Direction::South:
            directionY = 1.0F;
            break;

        case Direction::West:
            directionX = -1.0F;
            break;
    }

    // Draw direction indicator.
    SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);

    SDL_RenderLine(
        renderer_,
        centerX,
        centerY,
        centerX + directionX * SDL2D::DIRECTION_LENGTH,
        centerY + directionY * SDL2D::DIRECTION_LENGTH
    );
}
