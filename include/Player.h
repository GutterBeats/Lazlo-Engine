//
// Created by Anthony Lesch on 7/6/24.
//

#pragma once

#include "Entity.h"

class MovementComponent;
class SpriteComponent;

class Player final : public Entity
{
public:

    Player();

    void Tick(float deltaSeconds) override;

private:

    MovementComponent* m_MovementComponent = nullptr;

    SpriteComponent* m_SpriteComponent = nullptr;
};
