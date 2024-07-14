//
// Created by Anthony Lesch on 7/9/24.
//

#pragma once

#include <vector>

#include "Renderer.h"
#include "ECS.h"

class Brick;

class BrickManager final
{
public:
    explicit BrickManager(std::shared_ptr<ECS> ecs);

    ~BrickManager();

private:

    std::shared_ptr<ECS> m_Manager = nullptr;

    std::vector<Brick*> m_Bricks;
};
