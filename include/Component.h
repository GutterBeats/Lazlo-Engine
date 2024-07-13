//
// Created by Anthony Lesch on 7/12/24.
//

#pragma once

#include "ECS.h"
#include "Entity.h"

class Component
{
public:

    explicit Component(Entity* entity);
    virtual ~Component() = default;

    Entity* GetEntity();

    virtual void Initialize();

    virtual void Update(float deltaSeconds);

    virtual void Draw();

private:

    Entity* m_Entity;
};
