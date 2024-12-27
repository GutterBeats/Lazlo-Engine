//
// Created by Anthony Lesch on 12/5/24.
//

#include <SDL3/SDL.h>

#include "Application.h"
#include "EventSystem.h"
#include "Window.h"

namespace Lazlo
{
    Application::Application(const ApplicationConfig& config)
    {
        m_Config = config;
        m_EventSystem = new EventSystem();
    }

    bool Application::Initialize()
    {
        if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD))
        {
            SDL_Log("There was an error initializing SDL!: %s", SDL_GetError());
            return false;
        }

        m_Window = new Window(m_Config.Title, m_Config.Dimensions);

        return m_Window->GetIsInitialized();
    }

    void Application::Run()
    {
        m_IsRunning = true;

        SDL_Event event;
        auto lastFrame = static_cast<float>(SDL_GetTicks());

        const float ticksPerFrame = 1000.f / m_Config.FramesPerSecond;

        while (m_IsRunning)
        {
            const auto currentFrame = static_cast<float>(SDL_GetTicks());
            const float deltaSeconds = (currentFrame - lastFrame) / 1000.f;

            m_EventSystem->HandleInput();
            m_Window->Draw();

            const float frameTicks = static_cast<float>(SDL_GetTicks()) - currentFrame;
            if (frameTicks < ticksPerFrame)
            {
                // Wait remaining time
                SDL_Delay(ticksPerFrame - frameTicks);
            }

            lastFrame = currentFrame;
        }
    }

    void Application::Shutdown()
    {
        m_IsRunning = false;

        delete m_Window;
        SDL_Quit();
    }
} // Lazlo
