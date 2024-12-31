//
// Created by Anthony Lesch on 12/5/24.
//

#pragma once

#include <vector>

#include "ApplicationConfig.h"
#include "Window.h"

namespace Lazlo {

    class Application
    {
    public:

        explicit Application(const ApplicationConfig& config);

        bool Initialize();
        void Run();
        void Shutdown();

    private:

        std::vector<Window*> m_Windows;
        class EventSystem* m_EventSystem = nullptr;

        bool m_IsRunning = false;
        ApplicationConfig m_Config;
    };

} // Lazlo
