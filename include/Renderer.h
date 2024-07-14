//
// Created by Anthony Lesch on 7/12/24.
//

#pragma once

#include <SDL.h>

#include "Entity.h"

class Renderer final
{
public:
    explicit Renderer(SDL_Window* window);
    ~Renderer();

    [[nodiscard]]
    SDL_Renderer* GetRenderer() const;

    void RenderEntity(Entity& entity);

    void DrawTexture(SDL_Texture* texture, const SDL_Rect* sourceRect, const SDL_FRect* destRect) const;

    void StartFrame() const;

    void EndFrame() const;

private:

    SDL_Renderer* m_Renderer;
};
