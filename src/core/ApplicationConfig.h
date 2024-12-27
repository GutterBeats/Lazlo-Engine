//
// Created by Anthony Lesch on 12/5/24.
//

#pragma once

#include <string>
#include "core/Vector2D.h"

namespace Lazlo
{
    struct ApplicationConfig
    {
        /* Title of the window. */
        std::string Title;

        /* The dimensions of the window. */
        Vector2D Dimensions;

        /* The frame rate to run the application at. */
        float FramesPerSecond = 120.f;
    };
}
