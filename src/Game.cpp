//
// Created by Anthony Lesch on 7/5/24.
//

#include <SDL.h>
#include <string>

#include "Game.h"
#include "Player.h"
#include "Ball.h"
#include "BrickManager.h"
#include "Keyboard.h"

static const int WIDTH = 1280;
static const int HEIGHT = 720;

void Game::Initialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        SDL_Log("Unable to initialize SDL!: %s", SDL_GetError());
        return;
    }

    m_Window = new Window("Brick Breaker", WIDTH, HEIGHT);
    m_Renderer = m_Window->CreateRenderer();

    m_Manager = new ECS();

    m_Player = new Player(m_Renderer, WIDTH / 2.f, HEIGHT - 100, WIDTH);
    m_Ball = new Ball(m_Renderer, WIDTH / 2.f, HEIGHT / 2.f, WIDTH, HEIGHT);
    m_BrickManager = new BrickManager();

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
    m_Player->Tick(deltaTime);
    m_Ball->Tick(deltaTime);
}

void Game::RenderFrame()
{
    m_Renderer->StartFrame();

    m_Renderer->RenderEntity(*m_Player);
    m_Renderer->RenderEntity(*m_Ball);
    m_BrickManager->RenderBricks(*m_Renderer);

    m_Renderer->EndFrame();
}

void Game::Cleanup()
{
    delete m_Player;
    delete m_Ball;
    delete m_BrickManager;
    delete m_Renderer;
    delete m_Window;

    SDL_Quit();
}
