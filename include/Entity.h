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

    /*
     * Called before the entity is ticked the first time.
     * */
    virtual void Initialize();

    [[nodiscard]]
    bool GetIsActive() const;

    [[nodiscard]]
    bool GetIsInitialized() const;

    void Destroy();

    [[nodiscard]]
    VectorF2D GetEntityLocation() const;

    void SetEntityLocation(const VectorF2D& location);

    template<typename T> requires std::is_base_of_v<Component, T>
    [[nodiscard]] bool HasComponent() const;

    template<typename T> requires std::is_base_of_v<Component, T>
    [[nodiscard]] T* AddComponent()
    {
        T* component = new T();
        component->SetOwner(this);

        std::unique_ptr<Component> uniquePtr { component };
        m_Components.push_back(std::move(uniquePtr));

        m_ComponentArray[GetComponentTypeID<T>()] = component;
        m_ComponentBitSet[GetComponentTypeID<T>()] = true;

        return component;
    }

    template<typename T> requires std::is_base_of_v<Component, T>
    [[nodiscard]] T& GetComponent() const;

private:

    VectorF2D m_EntityLocation;

    bool m_IsActive = true;

    bool m_IsInitialized = false;

    std::vector<std::unique_ptr<Component>> m_Components;

    ComponentArray m_ComponentArray { };

    ComponentBitSet m_ComponentBitSet { };
};
