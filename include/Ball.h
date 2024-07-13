//
// Created by Anthony Lesch on 7/6/24.
//

#pragma once

#include "Entity.h"
#include "Renderer.h"

class Ball final : public Entity
{
public:
    Ball(Renderer* renderer, float x, float y, int screenWidth, int screenHeight);

    void Tick(float deltaSeconds) override;

private:

    int m_ScreenWidth = 0;

    int m_ScreenHeight = 0;

    int m_BallSpeedX;

    int m_BallSpeedY;
};
