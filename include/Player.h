//
// Created by Anthony Lesch on 7/6/24.
//

#pragma once

#include "Entity.h"
#include "Renderer.h"
#include "MovementComponent.h"
#include "SpriteComponent.h"

class Player final : public Entity
{
public:

    Player();

    void Tick(float deltaSeconds) override;

private:

    MovementComponent* m_MovementComponent = nullptr;

    SpriteComponent* m_SpriteComponent = nullptr;
};
