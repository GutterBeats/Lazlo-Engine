//
// Created by Anthony Lesch on 7/6/24.
//

#include <cmath>

#include "Player.h"
#include "TextureLoader.h"
#include "Keyboard.h"

static const int PADDLE_WIDTH = 104;
static const int PADDLE_HEIGHT = 24;
static const int MOVE_SPEED = 350;

#define PLAYER_TEXTURE ("resources/Textures/paddleBlue.png")

Player::Player(Renderer* renderer, float x, float y, int screenWidth)
    : Entity(x, y, PADDLE_WIDTH, PADDLE_HEIGHT), m_ScreenWidth(screenWidth)
{
    m_DestinationX = x;
    Texture = TextureLoader::LoadTextureFromFile(renderer, PLAYER_TEXTURE);
}

void Player::Tick(float deltaTime)
{
    Entity::Tick(deltaTime);

    if (Keyboard::IsLeftKeyDown())
    {
        m_DestinationX -= (MOVE_SPEED * deltaTime);
        m_DestinationX = std::max(m_DestinationX, 0.f);
    }
    else if (Keyboard::IsRightKeyDown())
    {
        m_DestinationX += (MOVE_SPEED * deltaTime);
        m_DestinationX = std::min(m_DestinationX, float(m_ScreenWidth) - Bounds.w);
    }

    Bounds.x = std::lerp(m_DestinationX, Bounds.x, pow(0.9f, deltaTime * 60));
}
