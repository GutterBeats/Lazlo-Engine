//
// Created by Anthony Lesch on 12/5/24.
//

#pragma once

#include <SDL3/SDL_video.h>

#include "ApplicationConfig.h"
#include "Renderer.h"

namespace Lazlo {

    class Window
    {
    public:

        Window(const std::string& title, Vector2D dimensions);
        ~Window();

        [[nodiscard]] bool GetIsInitialized() const;

        template<typename T>
        void BindEvent();

        void HandleInput();
        void Draw();

    private:

        /* Underlying window used for the application. */
        SDL_Window* m_Window = nullptr;

        Renderer* m_Renderer = nullptr;

        bool m_IsInitialized = false;
    };
} // Lazlo
