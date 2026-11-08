#include <SDL3/SDL.h>

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "dungeon/Dungeon.hh"
#include "player/Player.hh"
#include "rendering/SDL2DDungeonRenderer.hh"
#include "rendering/SDL2DPlayerRenderer.hh"

void printDungeon(const Dungeon& dungeon) {
std::cout << "Dungeon dimensions: "
          << dungeon.width() << "x"
          << dungeon.height() << "\n\n";

for (int y = 0; y < dungeon.height(); ++y)
    {
        for (int x = 0; x < dungeon.width(); ++x)
        {
            const Tile& tile = dungeon.tileAt(x, y);

            switch (tile.type)
            {
                case TileType::Wall:
                    std::cout << '#';
                    break;

                case TileType::Floor:
                    std::cout << '.';
                    break;
            }
        }

        std::cout << '\n';
    }
}

int main(int argc, char* argv[])
{
    const std::vector<std::string> map = {
        "########",
        "#......#",
        "#..##..#",
        "#......#",
        "#...#..#",
        "#......#",
        "########"
    };

	Dungeon dungeon(map);
	printDungeon(dungeon);
	Player player(1, 1, Direction::South);

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cerr << "Failed to initialize SDL: "
                  << SDL_GetError() << '\n';
        return EXIT_FAILURE;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Bloodwych",
        1280,
        720,
        SDL_WINDOW_RESIZABLE);

    if (!window)
    {
        std::cerr << "Failed to create window: "
                  << SDL_GetError() << '\n';

        SDL_Quit();
        return EXIT_FAILURE;
    }

	SDL_Renderer* sdlRenderer = SDL_CreateRenderer(window, nullptr);
	if (sdlRenderer == nullptr)
	{
	    std::cerr << "Failed to create renderer: "
	              << SDL_GetError() << '\n';

    	SDL_DestroyWindow(window);
    	SDL_Quit();
    	return EXIT_FAILURE;
	}

    SDL2DViewport viewport(sdlRenderer, dungeon.width(), dungeon.height());

	SDL2DDungeonRenderer dungeonRenderer(sdlRenderer, viewport, dungeon);
	SDL2DPlayerRenderer playerRenderer(sdlRenderer, viewport, dungeon);


    bool running = true;

    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;

                case SDL_EVENT_KEY_DOWN:
                    if (event.key.key == SDLK_ESCAPE)
                        running = false;
                    break;

                case SDL_EVENT_WINDOW_RESIZED:
                    viewport.update();
                    break;

                default:
                    break;
            }
        }

		SDL_SetRenderDrawColor(sdlRenderer, 20, 20, 25, 255);
		SDL_RenderClear(sdlRenderer);

		dungeonRenderer.render();
		playerRenderer.render(player);

		SDL_RenderPresent(sdlRenderer);


        //SDL_Delay(16);
    }

	SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
