//
// Created by Anthony Lesch on 7/5/24.
//

#pragma once

#include <memory>
#include <vector>

#include "Renderer.h"
#include "Window.h"
#include "BrickManager.h"

class Game final
{
public:

    explicit Game(std::shared_ptr<ECS> ecs);

    void Initialize();

    void HandleEvents();

    void UpdateEntities(float deltaTime);

    void RenderFrame();

    [[nodiscard]]
    bool GetIsRunning() const { return m_IsRunning; }

private:

    /* Flag to indicate whether the game is running. */
    bool m_IsRunning = false;

    /* SDL Window to render to. */
    std::unique_ptr<Window> m_Window = nullptr;

    /* SDL Renderer to use for rendering. */
    std::unique_ptr<Renderer> m_Renderer = nullptr;

    /* ECS Manager */
    std::shared_ptr<ECS> m_Manager = nullptr;

    /* Collection of bricks. */
    std::unique_ptr<BrickManager> m_BrickManager = nullptr;
};
