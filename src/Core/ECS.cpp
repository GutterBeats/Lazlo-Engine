//
// Created by Anthony Lesch on 7/11/24.
//

#include "ECS.h"
#include "Renderer.h"
#include "Entity.h"

void ECS::Update(const float deltaSeconds) const
{
    for (auto& entity: m_Entities)
    {
        if (!entity->GetIsInitialized()) [[unlikely]]
        {
            entity->Initialize();
        }

        entity->Tick(deltaSeconds);
    }
}

void ECS::Draw(Renderer& renderer) const
{
    for (auto& entity: m_Entities)
    {
        renderer.RenderEntity(*entity);
    }
}

void ECS::Refresh()
{
    if (m_Entities.empty()) return;

    std::erase_if(
        m_Entities,
        [](const std::unique_ptr<Entity>& entity)
        {
            return !entity->GetIsActive();
        });
}
