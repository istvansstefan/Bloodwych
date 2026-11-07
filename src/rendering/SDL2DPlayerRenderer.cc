#include "SDL2DPlayerRenderer.hh"
#include "SDL2DConstants.hh"

SDL2DPlayerRenderer::SDL2DPlayerRenderer(SDL_Renderer* renderer, const Dungeon& dungeon) :
    renderer_(renderer),
    dungeon_(dungeon),
    viewport_(renderer_, dungeon_.width(), dungeon_.height())
{
}

void SDL2DPlayerRenderer::render(const Player& player)
{
    const SDL_FPoint playerCenter = viewport_.tileCenter(player.x() + 0.5F, player.y() + 0.5F);

    // Calculate player position in screen coordinates.
    //const float centerX =
    //    offsetX + (player.x() + 0.5F) * SDL2D::TILE_SIZE;

    //const float centerY =
    //    offsetY + (player.y() + 0.5F) * SDL2D::TILE_SIZE;

    // Draw player marker.
    SDL_SetRenderDrawColor(renderer_, 220, 60, 60, 255);

    SDL_FRect playerRect = {
        playerCenter.x - SDL2D::PLAYER_SIZE / 2.0F,
        playerCenter.y - SDL2D::PLAYER_SIZE / 2.0F,
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
        playerCenter.x,
        playerCenter.y,
        playerCenter.x + directionX * SDL2D::DIRECTION_LENGTH,
        playerCenter.y + directionY * SDL2D::DIRECTION_LENGTH
    );
}
