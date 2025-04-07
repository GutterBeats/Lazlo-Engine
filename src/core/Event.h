//
// Created by Anthony Lesch on 12/18/24.
//

#pragma once

namespace Lazlo {

    enum class EventType
    {
        None,
        WindowResize, WindowMinimize, WindowRestore,
        ApplicationExit,
        KeyPress, KeyRelease
    };

    class Event
    {

    };
}
