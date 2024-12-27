//
// Created by Anthony Lesch on 12/5/24.
//

#pragma once

#include <SDL3/SDL_render.h>

namespace Lazlo
{

class Renderer
{
    /* The renderer used for the application. */
    SDL_Renderer* m_Renderer = nullptr;

public:

    explicit Renderer(SDL_Window* window);
    ~Renderer();

    void StartFrame() const;
    void EndFrame() const;
};

} // Lazlo
