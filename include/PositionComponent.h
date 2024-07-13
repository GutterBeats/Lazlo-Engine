//
// Created by Anthony Lesch on 7/12/24.
//

#pragma once

#include "Component.h"

class PositionComponent final : public Component
{
public:

    void Initialize() override;

    void Update(float deltaSeconds) override;
};
