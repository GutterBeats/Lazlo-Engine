//
// Created by Anthony Lesch on 12/5/24.
//

#include "Renderer.h"

namespace Lazlo
{
    Renderer::Renderer(SDL_Window* window)
    {
        m_Renderer = SDL_CreateRenderer(window, nullptr);
    }

    Renderer::~Renderer()
    {
        SDL_DestroyRenderer(m_Renderer);
    }

    void Renderer::StartFrame() const
    {
        SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(m_Renderer);
    }

    void Renderer::EndFrame() const
    {
        SDL_RenderPresent(m_Renderer);
    }
} // Lazlo
