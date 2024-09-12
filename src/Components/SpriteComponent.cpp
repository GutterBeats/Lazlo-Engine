//
// Created by Anthony Lesch on 7/13/24.
//

#include "SpriteComponent.h"
#include "Renderer.h"
#include "TextureLoader.h"

void SpriteComponent::Initialize()
{
    Component::Initialize();

    const Entity* owner = GetOwner();
    if (owner == nullptr) return;

    const auto [X, Y] = owner->GetEntityLocation();
    m_Bounds.x = X;
    m_Bounds.y = Y;
}

void SpriteComponent::Update(const float deltaSeconds)
{
    Component::Update(deltaSeconds);

    const Entity* owner = GetOwner();
    if (owner == nullptr) return;

    const auto [X, Y] = owner->GetEntityLocation();
    m_Bounds.x = X;
    m_Bounds.y = Y;
}

void SpriteComponent::Draw(Renderer& renderer)
{
    Component::Draw(renderer);

    if (m_Sprite == nullptr) [[unlikely]]
    {
        m_Sprite = TextureLoader::LoadTextureFromFile(&renderer, m_SpritePath);
    }

    renderer.DrawTexture(m_Sprite, nullptr, &m_Bounds);
}

void SpriteComponent::SetSpritePath(const char* path)
{
    if (m_Sprite != nullptr)
    {
        SDL_DestroyTexture(m_Sprite);
    }

    m_SpritePath = path;
}

void SpriteComponent::SetSize(const float width, const float height)
{
    m_Bounds.w = width;
    m_Bounds.h = height;
}
