//
// Created by Anthony Lesch on 7/6/24.
//

#include <SDL.h>

#include "Ball.h"
#include "TextureLoader.h"

static const int BALL_RADIUS = 22;

#define BALL_PATH ("resources/Textures/ballBlue.png")

Ball::Ball(Renderer* renderer, float x, float y, int screenWidth, int screenHeight)
    : Entity(x, y, BALL_RADIUS, BALL_RADIUS), m_ScreenWidth(screenWidth), m_ScreenHeight(screenHeight)
{
    Texture = TextureLoader::LoadTextureFromFile(renderer, BALL_PATH);
    m_BallSpeedX = 200;
    m_BallSpeedY = 200;
}

void Ball::Tick(float deltaTime)
{
    Entity::Tick(deltaTime);

    if (Bounds.x + BALL_RADIUS >= float(m_ScreenWidth) || Bounds.x <= 0.f)
    {
        m_BallSpeedX *= -1;
    }

    if (Bounds.y + BALL_RADIUS >= float(m_ScreenHeight) || Bounds.y <= 0.f)
    {
        m_BallSpeedY *= -1;
    }

    Bounds.x += (float(m_BallSpeedX) * deltaTime);
    Bounds.y += (float(m_BallSpeedY) * deltaTime);
}
