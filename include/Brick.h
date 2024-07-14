//
// Created by Anthony Lesch on 7/6/24.
//

#pragma once

#include "Entity.h"
#include "Renderer.h"

class Brick final : public Entity
{
public:
    Brick();

    void Draw(Renderer& renderer) override;

private:

    int m_MaxBrickHealth;

    int m_BrickHealth;
};
