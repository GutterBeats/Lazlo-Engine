//
// Created by Anthony Lesch on 7/7/24.
//

#pragma once

#include <SDL.h>

typedef struct keymap
{
    SDL_Scancode Left;
    SDL_Scancode Right;
    SDL_Scancode Quit;
    SDL_Scancode Pause;
} KeyMap;

typedef struct keyState
{
    bool Left;
    bool Right;
} KeyState;

enum KBD_KEY_STATE
{
    KEY_STATE_UP,
    KEY_STATE_DOWN
};

class Keyboard final
{
public:
    Keyboard() = delete;

    static void InitializeKeymap();

    static void HandleEvent(const SDL_Event& event);

    static bool IsLeftKeyDown();

    static bool IsRightKeyDown();

private:

    static void HandleRealtimeKeys(SDL_Scancode scancode, enum KBD_KEY_STATE state);
};
