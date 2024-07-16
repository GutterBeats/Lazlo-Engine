//
// Created by Anthony Lesch on 7/6/24.
//

#include <SDL.h>

#include "Ball.h"
#include "TextureLoader.h"
#include "MovementComponent.h"
#include "SpriteComponent.h"

static const int BALL_RADIUS = 22;

#define BALL_PATH ("resources/Textures/ballBlue.png")

Ball::Ball()
{
    m_MovementComponent = AddComponent<MovementComponent>();
    m_MovementComponent->SetMovementSpeed(200.f);

    m_SpriteComponent = AddComponent<SpriteComponent>();
    m_SpriteComponent->SetSpritePath(BALL_PATH);
    m_SpriteComponent->SetSize(BALL_RADIUS, BALL_RADIUS);
}

void Ball::Tick(float deltaTime)
{
    Entity::Tick(deltaTime);

//    if (Bounds.x + BALL_RADIUS >= float(m_ScreenWidth) || Bounds.x <= 0.f)
//    {
//        m_BallSpeedX *= -1;
//    }
//
//    if (Bounds.y + BALL_RADIUS >= float(m_ScreenHeight) || Bounds.y <= 0.f)
//    {
//        m_BallSpeedY *= -1;
//    }
//
//    Bounds.x += (float(m_BallSpeedX) * deltaTime);
//    Bounds.y += (float(m_BallSpeedY) * deltaTime);
}
