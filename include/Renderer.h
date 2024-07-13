//
// Created by Anthony Lesch on 7/12/24.
//

#pragma once

#include <SDL.h>

#include "Entity.h"

class Renderer
{
public:
    explicit Renderer(SDL_Window* window);
    ~Renderer();

    [[nodiscard]]
    SDL_Renderer* GetRenderer() const;

    void RenderEntity(const Entity& entity) const;

    void StartFrame() const;

    void EndFrame() const;

private:

    SDL_Renderer* m_Renderer;
};
