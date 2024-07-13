#include <SDL.h>

#include "Game.h"
#include "TextureLoader.h"
#include "Keyboard.h"

int main()
{
    TextureLoader::Initialize();
    Keyboard::InitializeKeymap();

    Game game;
    game.Initialize();

    uint64_t tick = SDL_GetTicks64();

    while (game.GetIsRunning())
    {
        uint64_t current = SDL_GetTicks64();
        float deltaTime = float(current - tick) / 1000.f;

        game.HandleEvents();
        game.UpdateEntities(deltaTime);
        game.RenderFrame();

        tick = current;
    }

    game.Cleanup();
    TextureLoader::Exit();
}
