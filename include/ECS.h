//
// Created by Anthony Lesch on 7/11/24.
//

#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

#include "Component.h"

class Entity;
class Renderer;

constexpr std::size_t MaxComponents = 32;

using ComponentTypeID = std::size_t;
using ComponentBitSet = std::bitset<MaxComponents>;
using ComponentArray = std::array<Component*, MaxComponents>;

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

class ECS final
{
public:

    void Update(float deltaSeconds) const;

    void Draw(Renderer& renderer) const;

    void Refresh();

    template<typename T> requires std::is_base_of_v<Entity, T>
    [[nodiscard]] T& AddEntity()
    {
        T* entity = new T();
        std::unique_ptr<T> uniquePtr { entity };

        m_Entities.push_back(std::move(uniquePtr));

        return *entity;
    }

private:

    /*
     * Collection of entities managed by this ECS instance.
     * */
    std::vector<std::unique_ptr<Entity>> m_Entities;
};
