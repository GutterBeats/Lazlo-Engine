//
// Created by Anthony Lesch on 7/11/24.
//

#include <type_traits>

#include "ECS.h"
#include "Renderer.h"
#include "Entity.h"

inline ComponentTypeID GetComponentTypeID()
{
    static ComponentTypeID lastID = 0;

    return lastID++;
}

template<typename T>
inline ComponentTypeID GetComponentTypeID() noexcept
{
    static ComponentTypeID componentID = GetComponentTypeID();

    return componentID;
}

void ECS::Update(float deltaSeconds)
{
    for (auto& entity: m_Entities)
    {
        entity->Tick(deltaSeconds);
    }
}

void ECS::Draw(Renderer& renderer)
{
    for (auto& entity: m_Entities)
    {
        renderer.RenderEntity(*entity);
    }
}

void ECS::Refresh()
{
    if (m_Entities.empty()) return;

    m_Entities.erase(
            std::remove_if(
                    m_Entities.begin(),
                    m_Entities.end(),
                    [](const std::unique_ptr<Entity>& entity)
                    {
                        return entity->GetIsActive();
                    }),
                    m_Entities.end()
            );
}

Entity& ECS::AddEntity()
{
    auto entity = new Entity(1,2,3,4);
    std::unique_ptr<Entity> uniquePtr { entity };

    m_Entities.push_back(std::move(uniquePtr));

    return *entity;
}
