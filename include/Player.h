//
// Created by Anthony Lesch on 7/6/24.
//

#pragma once

#include "Entity.h"
#include "Renderer.h"

class Player final : public Entity
{
public:

    /*
     * Create a new Player object with the provided screen width and height.
     *
     * @param renderer SDL_Renderer object to use for loading player texture.
     * @param x Starting X position of the player
     * @param y Starting Y position of the player
     * */
    Player(Renderer* renderer, float x, float y, int screenWidth);

    void Tick(float deltaSeconds) override;

private:

    /*
     * Destination X Coordinate
     * */
    float m_DestinationX {};

    int m_ScreenWidth = 0;
};
