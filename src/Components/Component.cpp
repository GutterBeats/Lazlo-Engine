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
    if (m_Entity.expired()) return nullptr;

    return m_Entity.lock().get();
}

void Component::SetOwner(Entity* owner)
{

}
