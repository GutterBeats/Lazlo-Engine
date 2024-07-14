//
// Created by Anthony Lesch on 7/11/24.
//

#pragma once

#include <vector>

#include "ECS.h"
#include "Types.h"
#include "Component.h"

class Entity
{
public:

    virtual ~Entity() = default;

    /*
     * Draw the entity on the screen.
     * */
    virtual void Draw(Renderer& renderer);

    /*
     * Update the entity each frame.
     * */
    virtual void Tick(float deltaSeconds);

    [[nodiscard]]
    bool GetIsActive() const;

    void Destroy();

    [[nodiscard]]
    Vector2D GetEntityLocation() const;

    void SetEntityLocation(const Vector2D& location);

    template<typename T> requires std::is_base_of_v<Component, T>
    [[nodiscard]] bool HasComponent() const;

    template<typename T> requires std::is_base_of_v<Component, T>
    [[nodiscard]] T* AddComponent()
    {
        T* component = new T();
        std::unique_ptr<Component> uniquePtr { component };
        m_Components.push_back(std::move(uniquePtr));

        m_ComponentArray[GetComponentTypeID<T>()] = component;
        m_ComponentBitSet[GetComponentTypeID<T>()] = true;

        component->Initialize();

        return component;
    }

    template<typename T> requires std::is_base_of_v<Component, T>
    [[nodiscard]] T& GetComponent() const;

private:

    Vector2D m_EntityLocation;

    bool m_IsActive = true;

    std::vector<std::unique_ptr<Component>> m_Components;

    ComponentArray m_ComponentArray { };

    ComponentBitSet m_ComponentBitSet { };
};
