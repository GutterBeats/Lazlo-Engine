//
// Created by Anthony Lesch on 7/5/24.
//

#pragma once

#include <vector>
#include "Renderer.h"
#include "Window.h"

class Player;
class BrickManager;
class Ball;
class TextWriter;

class Game final
{
public:

    void Initialize();

    void HandleEvents();

    void UpdateEntities(float deltaTime);

    void RenderFrame();

    void Cleanup();

    [[nodiscard]]
    bool GetIsRunning() const { return m_IsRunning; }

private:

    /* Flag to indicate whether the game is running. */
    bool m_IsRunning = false;

    /* SDL Window to render to. */
    Window* m_Window = nullptr;

    /* SDL Renderer to use for rendering. */
    Renderer* m_Renderer = nullptr;

    /* ECS Manager */
    ECS* m_Manager = nullptr;

    /* Player paddle. */
    Player* m_Player = nullptr;

    /* Pointer to ball. */
    Ball* m_Ball = nullptr;

    /* Collection of bricks. */
    BrickManager* m_BrickManager = nullptr;
};
