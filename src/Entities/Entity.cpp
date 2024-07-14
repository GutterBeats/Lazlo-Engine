//
// Created by Anthony Lesch on 7/11/24.
//

#include "Entity.h"

void Entity::Tick(float deltaSeconds)
{
    if (!m_IsActive) return;

    for (auto& comp: m_Components)
    {
        comp->Update(deltaSeconds);
    }
}

void Entity::Draw(Renderer& renderer)
{
    if (!m_IsActive) return;

    for (auto& comp: m_Components)
    {
        comp->Draw(renderer);
    }
}

bool Entity::GetIsActive() const
{
    return m_IsActive;
}

void Entity::Destroy()
{
    m_IsActive = false;
}

Vector2D Entity::GetEntityLocation() const
{
    return m_EntityLocation;
}

void Entity::SetEntityLocation(const Vector2D& location)
{
    m_EntityLocation.X = location.X;
    m_EntityLocation.Y = location.Y;
}

template<typename T> requires std::is_base_of_v<Component, T>
bool Entity::HasComponent() const
{
    return m_ComponentBitSet[GetComponentTypeID<T>()];
}

template<typename T> requires std::is_base_of_v<Component, T>
T& Entity::GetComponent() const
{
    auto ptr(m_ComponentArray[GetComponentTypeID<T>()]);

    return *static_cast<T*>(ptr);
}
