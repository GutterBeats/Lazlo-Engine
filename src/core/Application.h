//
// Created by Anthony Lesch on 12/5/24.
//

#pragma once

#include "ApplicationConfig.h"

namespace Lazlo {

    class Application
{
    class Window* m_Window = nullptr;
    class EventSystem* m_EventSystem = nullptr;

public:

    explicit Application(const ApplicationConfig& config);

    bool Initialize();
    void Run();
    void Shutdown();

private:

    bool m_IsRunning = false;
    ApplicationConfig m_Config;
};

} // Lazlo
