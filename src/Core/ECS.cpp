//
// Created by Anthony Lesch on 7/11/24.
//

#include "ECS.h"
#include "Renderer.h"
#include "Entity.h"

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
                        return !entity->GetIsActive();
                    }),
                    m_Entities.end()
            );
}
