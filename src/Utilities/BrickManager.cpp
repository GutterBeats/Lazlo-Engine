//
// Created by Anthony Lesch on 7/9/24.
//

#include "BrickManager.h"
#include "Brick.h"

BrickManager::BrickManager(std::shared_ptr<ECS> ecs)
    : m_Manager(std::move(ecs))
{
}

BrickManager::~BrickManager()
{
    if (m_Bricks.empty()) return;

    for (const auto& brick: m_Bricks)
    {
        delete brick;
    }
}
