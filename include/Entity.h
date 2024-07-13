//
// Created by Anthony Lesch on 7/11/24.
//

#pragma once

#include <SDL.h>
#include <vector>
#include "Component.h"

class Entity
{
public:
    Entity(float x, float y, float w, float h);

    virtual ~Entity();

    /*
     * Draw the entity on the screen.
     * */
    virtual void Draw(SDL_Renderer* renderer) const;

    /*
     * Update the entity each frame.
     * */
    virtual void Tick(float deltaSeconds);

    [[nodiscard]]
    bool GetIsActive() const;

    void Destroy();

    template<typename T>
    [[nodiscard]] bool HasComponent() const;

    template<typename T, typename... TArgs>
    [[nodiscard]] T& AddComponent(TArgs&&...args);

    template<typename T>
    [[nodiscard]] T& GetComponent() const;

protected:

    SDL_FRect Bounds;

    /*
     * Texture to use to represent player.
     * */
    SDL_Texture* Texture = nullptr;

private:

    bool m_IsActive = true;

    std::vector<std::unique_ptr<Component>> m_Components;

    ComponentArray m_ComponentArray { };

    ComponentBitSet m_ComponentBitSet { };
};
