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

    void SetMovementSpeed(float movementSpeed);

    void SetInterpolationSpeed(float interpolationSpeed);

    void AddMovementX(float x);

    void AddMovementY(float y);

private:

    /*
     * Destination X Coordinate
     * */
    float m_DestinationX = 0.f;

    /*
     * Destination Y Coordinate
     * */
    float m_DestinationY = 0.f;

    float m_MovementSpeed = 0.f;

    float m_InterpolationSpeed = 0.9f;
};
