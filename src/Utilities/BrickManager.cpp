//
// Created by Anthony Lesch on 7/9/24.
//

#include "BrickManager.h"
#include "Brick.h"

BrickManager::~BrickManager()
{
    if (m_Bricks.empty()) return;

    for (const auto& brick: m_Bricks)
    {
        delete brick;
    }
}

void BrickManager::RenderBricks(Renderer& renderer)
{
    for (const auto& brick: m_Bricks)
    {
        renderer.RenderEntity(*brick);
    }
}
