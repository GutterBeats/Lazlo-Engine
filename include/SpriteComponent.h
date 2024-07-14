//
// Created by Anthony Lesch on 7/13/24.
//

#pragma once

#include <SDL.h>
#include "Component.h"

class SpriteComponent final : public Component
{
public:

    void SetSize(int width, int height);

private:

    SDL_FRect m_Bounds { };
};
