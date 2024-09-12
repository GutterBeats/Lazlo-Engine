//
// Created by Anthony Lesch on 7/12/24.
//

#pragma once

#include <memory>

class Renderer;
class Entity;

class Component
{
public:

    Component() = default;

    virtual ~Component() = default;

    virtual void Initialize();

    virtual void Update(float deltaSeconds);

    virtual void Draw(Renderer& renderer);

    Entity* GetOwner() const;

    void SetOwner(Entity* owner);

private:

    Entity* m_Entity = nullptr;
};
