//
// Created by Anthony Lesch on 7/13/24.
//

#pragma once

#include <vector>

#include "Component.h"
#include "Physics.h"

class Entity;

using CollisionCallback = void (*) (Entity* collider, Entity* other, CollisionType type);

class CollisionComponent final : public Component
{
private:

    std::vector<CollisionCallback> m_Callbacks;
};
