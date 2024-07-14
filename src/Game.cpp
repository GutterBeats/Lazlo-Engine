//
// Created by Anthony Lesch on 7/5/24.
//

#include <SDL.h>
#include <string>
#include <utility>

#include "Game.h"
#include "Player.h"
#include "Ball.h"
#include "BrickManager.h"
#include "Keyboard.h"

static const int WIDTH = 1280;
static const int HEIGHT = 720;

Game::Game(std::shared_ptr<ECS> ecs)
    : m_Manager(std::move(ecs))
{
}

void Game::Initialize()
{
    m_Window = std::make_unique<Window>("Brick Breaker", WIDTH, HEIGHT);
    m_Renderer = std::unique_ptr<Renderer>(m_Window->CreateRenderer());
    m_BrickManager = std::make_unique<BrickManager>(m_Manager);

    m_IsRunning = true;
}

void Game::HandleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) [[unlikely]]
        {
            m_IsRunning = false;
            return;
        }

        Keyboard::HandleEvent(event);
    }
}

void Game::UpdateEntities(float deltaTime)
{
    m_Manager->Update(deltaTime);
}

void Game::RenderFrame()
{
    m_Renderer->StartFrame();
    m_Manager->Draw(*m_Renderer);
    m_Renderer->EndFrame();
}
