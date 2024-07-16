//
// Created by Anthony Lesch on 7/12/24.
//

#include "Component.h"

void Component::Initialize()
{
}

void Component::Update(float deltaSeconds)
{
}

void Component::Draw(Renderer& renderer)
{
}

Entity* Component::GetOwner()
{
    return m_Entity;
}

void Component::SetOwner(Entity* owner)
{
    m_Entity = owner;
}
