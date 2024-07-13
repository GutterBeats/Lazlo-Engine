//
// Created by Anthony Lesch on 7/6/24.
//

#pragma once

#include "Entity.h"
#include "Renderer.h"

class Brick final : public Entity
{
public:
    Brick(Renderer* renderer, float x, float y, int brickHealth = 25);
    ~Brick() override;

    void Draw(SDL_Renderer* renderer) const override;

    [[nodiscard]]
    bool GetIsAlive() const { return m_BrickHealth > 0; }

private:

    SDL_Texture* m_LowHealthTexture = nullptr;

    int m_MaxBrickHealth;

    int m_BrickHealth;
};
