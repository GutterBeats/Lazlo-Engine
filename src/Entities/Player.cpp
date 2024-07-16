//
// Created by Anthony Lesch on 7/6/24.
//

#include "Player.h"
#include "TextureLoader.h"
#include "Keyboard.h"
#include "SpriteComponent.h"
#include "MovementComponent.h"

static const int PADDLE_WIDTH = 104;
static const int PADDLE_HEIGHT = 24;
static const int MOVE_SPEED = 350;

#define PLAYER_TEXTURE ("resources/Textures/paddleBlue.png")

Player::Player()
{
    m_MovementComponent = AddComponent<MovementComponent>();
    m_MovementComponent->SetMovementSpeed(MOVE_SPEED);

    m_SpriteComponent = AddComponent<SpriteComponent>();
    m_SpriteComponent->SetSize(PADDLE_WIDTH, PADDLE_HEIGHT);
    m_SpriteComponent->SetSpritePath(PLAYER_TEXTURE);
}

void Player::Tick(float deltaTime)
{
    Entity::Tick(deltaTime);

    if (Keyboard::IsLeftKeyDown())
    {
        m_MovementComponent->AddMovementX(-deltaTime);

//        m_DestinationX = std::max(m_DestinationX, 0.f);
    }
    else if (Keyboard::IsRightKeyDown())
    {
        m_MovementComponent->AddMovementX(deltaTime);
        //m_DestinationX = std::min(m_DestinationX, float(m_ScreenWidth) - Bounds.w);
    }
}
