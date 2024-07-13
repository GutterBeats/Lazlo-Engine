//
// Created by Anthony Lesch on 7/11/24.
//

#include "Entity.h"

Entity::Entity(float x, float y, float w, float h)
    : Bounds({ .x = x, .y = y, .w = w, .h = h })
{

}

void Entity::Tick(float deltaSeconds)
{
    for (auto& comp: m_Components)
    {
        comp->Update(deltaSeconds);
    }
}

Entity::~Entity()
{
    SDL_DestroyTexture(Texture);
}

void Entity::Draw(SDL_Renderer* renderer) const
{
    SDL_RenderCopyF(renderer, Texture, nullptr, &Bounds);

    for (auto& comp: m_Components)
    {
        comp->Draw();
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

template<typename T>
bool Entity::HasComponent() const
{
    return m_ComponentBitSet[GetComponentTypeID<T>()];
}

template<typename T, typename... TArgs>
T& Entity::AddComponent(TArgs&& ... args)
{
    T* component(new T(std::forward<TArgs>(args)...));
    std::unique_ptr<Component> uniquePtr { component };
    m_Components.emplace_back(std::move(uniquePtr));

    m_ComponentArray[GetComponentTypeID<T>()] = component;
    m_ComponentBitSet[GetComponentTypeID<T>()] = true;

    component->Initialize();

    return *component;
}

template<typename T>
T& Entity::GetComponent() const
{
    auto ptr(m_ComponentArray[GetComponentTypeID<T>()]);

    return *static_cast<T*>(ptr);
}
