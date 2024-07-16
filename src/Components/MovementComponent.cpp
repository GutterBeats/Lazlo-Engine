//
// Created by Anthony Lesch on 7/12/24.
//

#include <cmath>

#include "MovementComponent.h"
#include "Entity.h"

void MovementComponent::Initialize()
{
    Component::Initialize();

    if (Entity* owner = GetOwner())
    {
        const VectorF2D location = owner->GetEntityLocation();

        m_DestinationX = location.X;
        m_DestinationY = location.Y;
    }
}

void MovementComponent::Update(float deltaSeconds)
{
    Component::Update(deltaSeconds);

    if (Entity* owner = GetOwner())
    {
        VectorF2D location = owner->GetEntityLocation();

        float interpolation = pow(m_InterpolationSpeed, deltaSeconds * 60);

        location.X = std::lerp(m_DestinationX, location.X, interpolation);
        location.Y = std::lerp(m_DestinationY, location.Y, interpolation);

        owner->SetEntityLocation(location);
    }
}

void MovementComponent::SetMovementSpeed(float movementSpeed)
{
    m_MovementSpeed = movementSpeed;
}

void MovementComponent::SetInterpolationSpeed(float interpolationSpeed)
{
    m_InterpolationSpeed = interpolationSpeed;
}

void MovementComponent::AddMovementX(float x)
{
    m_DestinationX += (m_MovementSpeed * x);
}

void MovementComponent::AddMovementY(float y)
{
    m_DestinationY += (m_MovementSpeed * y);
}
