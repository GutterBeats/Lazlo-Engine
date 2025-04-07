//
// Created by Anthony Lesch on 12/5/24.
//

#include "Window.h"
#include "Logging.h"

namespace Lazlo {

    Window::Window(const std::string& title, const Vector2D dimensions)
    {
        m_Window = SDL_CreateWindow(title.c_str(), dimensions.X, dimensions.Y, SDL_WINDOW_OPENGL);

        if (!m_Window)
        {
            LZ_LOG("Unable to create SDL Window!: %s", SDL_GetError());
            return;
        }

        m_Renderer = new Renderer(m_Window);
        m_IsInitialized = true;
    }

    Window::~Window()
    {
        delete m_Renderer;
        SDL_DestroyWindow(m_Window);
    }

    bool Window::GetIsInitialized() const
    {
        return m_IsInitialized;
    }

    void Window::HandleInput()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_EVENT_QUIT:

                    break;
                case SDL_EVENT_KEY_UP:
                {
                    if (event.key.scancode == SDL_SCANCODE_ESCAPE)
                    {
                        SDL_Event quit { SDL_EVENT_QUIT };
                        SDL_PushEvent(&quit);
                    }
                }
                break;
                default:
                    break;
            }
        }
    }

    template<typename T>
    void Window::BindEvent()
    {
    }

    void Window::Draw()
    {
        m_Renderer->StartFrame();

        m_Renderer->EndFrame();
    }
} // Lazlo
