//
// Created by Anthony Lesch on 7/12/24.
//

#include "Component.h"

Component::Component(Entity* entity)
    : m_Entity(entity)
{
}

Entity* Component::GetEntity()
{
    return m_Entity;
}

void Component::Initialize()
{
}

void Component::Update(float deltaSeconds)
{
}

void Component::Draw()
{
}
