//
// Created by Anthony Lesch on 7/12/24.
//

#pragma once

#include <SDL.h>
#include "Renderer.h"

class Window
{
public:
    Window(const char* title, int width, int height);
    ~Window();

    [[nodiscard]]
    Renderer* CreateRenderer() const;

private:

    SDL_Window* m_Window;
};
