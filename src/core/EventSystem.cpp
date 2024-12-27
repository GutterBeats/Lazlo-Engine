//
// Created by Anthony Lesch on 12/18/24.
//

#include "EventSystem.h"

#include <SDL3/SDL_events.h>

namespace Lazlo {

    void EventSystem::HandleInput()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_EVENT_QUIT:

                break;
                case SDL_EVENT_KEY_UP:
                {
                    if (event.key.scancode == SDL_SCANCODE_ESCAPE)
                    {
                        SDL_Event quit { SDL_EVENT_QUIT };
                        SDL_PushEvent(&quit);
                    }
                }
                break;
                default:
                    break;
            }
        }
    }
} // Lazlo
