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

class Component;
class Entity;
class Renderer;

constexpr std::size_t MaxComponents = 32;

using ComponentTypeID = std::size_t;
using ComponentBitSet = std::bitset<MaxComponents>;
using ComponentArray = std::array<Component*, MaxComponents>;

inline ComponentTypeID GetComponentTypeID();

template<typename T>
inline ComponentTypeID GetComponentTypeID() noexcept;

class ECS final
{
public:

    void Update(float deltaSeconds);

    void Draw(Renderer& renderer);

    void Refresh();

    Entity& AddEntity();

private:
    std::vector<std::unique_ptr<Entity>> m_Entities;
};
