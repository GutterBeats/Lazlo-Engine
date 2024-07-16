//
// Created by Anthony Lesch on 7/13/24.
//

#pragma once

#include <SDL.h>

#include "Component.h"

class Renderer;

class SpriteComponent final : public Component
{
public:

    void Initialize() override;

    void Update(float deltaSeconds) override;

    void Draw(Renderer& renderer) override;

    void SetSpritePath(const char* path);

    void SetSize(float width, float height);

private:

    SDL_Texture* m_Sprite = nullptr;

    const char* m_SpritePath = nullptr;

    SDL_FRect m_Bounds { };
};
