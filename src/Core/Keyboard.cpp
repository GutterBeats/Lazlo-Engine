//
// Created by Anthony Lesch on 7/7/24.
//

#include "Keyboard.h"

static KeyMap s_KeyMap;
static KeyState s_KeyState;

void Keyboard::InitializeKeymap()
{
    s_KeyMap = {
        .Left = SDL_SCANCODE_A,
        .Right = SDL_SCANCODE_D,
        .Quit = SDL_SCANCODE_ESCAPE,
        .Pause = SDL_SCANCODE_TAB,
    };

    s_KeyState = {
        .Left = false,
        .Right = false,
    };
}

void Keyboard::HandleEvent(const SDL_Event& event)
{
    switch (event.type)
    {
        case SDL_KEYDOWN:
            HandleRealtimeKeys(event.key.keysym.scancode, KEY_STATE_DOWN);
            break;
        case SDL_KEYUP:
        {
            HandleRealtimeKeys(event.key.keysym.scancode, KEY_STATE_UP);

            if (event.key.keysym.scancode == s_KeyMap.Quit)
            {
                SDL_Event quit { SDL_QUIT };
                SDL_PushEvent(&quit);

                return;
            }
        }
            break;
        default:
            break;
    }
}

bool Keyboard::IsLeftKeyDown()
{
    return s_KeyState.Left;
}

bool Keyboard::IsRightKeyDown()
{
    return s_KeyState.Right;
}

void Keyboard::HandleRealtimeKeys(SDL_Scancode scancode, enum KBD_KEY_STATE state)
{
    if (s_KeyMap.Left == scancode)
    {
        s_KeyState.Left = state;
    }
    else if (s_KeyMap.Right == scancode)
    {
        s_KeyState.Right = state;
    }
}
