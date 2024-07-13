//
// Created by Anthony Lesch on 7/12/24.
//

#include "Window.h"

Window::Window(const char* title, int width, int height)
{
    m_Window = SDL_CreateWindow(title,
                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                width, height,
                                SDL_WINDOW_METAL | SDL_WINDOW_SHOWN);

    if (m_Window == nullptr)
    {
        SDL_Log("Unable to create a window!: %s", SDL_GetError());
        exit(1);
    }
}

Renderer* Window::CreateRenderer() const
{
    return new Renderer(m_Window);
}

Window::~Window()
{
    SDL_DestroyWindow(m_Window);
}
