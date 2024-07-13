//
// Created by Anthony Lesch on 7/9/24.
//

#pragma once

#include <vector>

#include "Renderer.h"

class Brick;

class BrickManager final
{
public:
    BrickManager() = default;
    ~BrickManager();

    void RenderBricks(Renderer& renderer);

private:

    std::vector<Brick*> m_Bricks;
};
