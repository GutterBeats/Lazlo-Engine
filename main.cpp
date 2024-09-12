#include <SDL.h>

#include "Game.h"
#include "TextureLoader.h"
#include "Keyboard.h"

int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        SDL_Log("Unable to initialize SDL!: %s", SDL_GetError());
        return -1;
    }

    atexit(SDL_Quit);

    TextureLoader::Initialize();
    Keyboard::InitializeKeymap();

    auto ecs = std::make_shared<ECS>();
    const auto game = std::make_unique<Game>(ecs);
    game->Initialize();

    uint64_t tick = SDL_GetTicks64();

    while (game->GetIsRunning())
    {
        const uint64_t current = SDL_GetTicks64();
        const float deltaTime = static_cast<float>(current - tick) / 1000.f;

        game->HandleEvents();
        game->UpdateEntities(deltaTime);
        game->RenderFrame();

        ecs->Refresh();

        tick = current;
    }

    TextureLoader::Exit();
}
