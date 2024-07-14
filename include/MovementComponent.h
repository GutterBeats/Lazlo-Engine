//
// Created by Anthony Lesch on 7/12/24.
//

#pragma once

#include "Component.h"

class MovementComponent final : public Component
{
public:

    void Initialize() override;

    void Update(float deltaSeconds) override;

private:

    /*
     * Destination X Coordinate
     * */
    float m_DestinationX = 0.f;

    /*
     * Destination Y Coordinate
     * */
    float m_DestinationY = 0.f;
};
