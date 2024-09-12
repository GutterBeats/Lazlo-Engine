//
// Created by Anthony Lesch on 7/12/24.
//

#include <cmath>

#include "MovementComponent.h"
#include "Entity.h"

void MovementComponent::Initialize()
{
    Component::Initialize();

    if (const Entity* owner = GetOwner())
    {
        const auto [X, Y] = owner->GetEntityLocation();

        m_DestinationX = X;
        m_DestinationY = Y;
    }
}

void MovementComponent::Update(const float deltaSeconds)
{
    Component::Update(deltaSeconds);

    if (Entity* owner = GetOwner())
    {
        VectorF2D location = owner->GetEntityLocation();

        const float interpolation = pow(m_InterpolationSpeed, deltaSeconds * 60);

        location.X = std::lerp(m_DestinationX, location.X, interpolation);
        location.Y = std::lerp(m_DestinationY, location.Y, interpolation);

        owner->SetEntityLocation(location);
    }
}

void MovementComponent::SetMovementSpeed(const float movementSpeed)
{
    m_MovementSpeed = movementSpeed;
}

void MovementComponent::SetInterpolationSpeed(const float interpolationSpeed)
{
    m_InterpolationSpeed = interpolationSpeed;
}

void MovementComponent::AddMovementX(const float x)
{
    m_DestinationX += m_MovementSpeed * x;
}

void MovementComponent::AddMovementY(const float y)
{
    m_DestinationY += m_MovementSpeed * y;
}
