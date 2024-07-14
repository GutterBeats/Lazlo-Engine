//
// Created by Anthony Lesch on 7/6/24.
//

#include "Brick.h"
#include "TextureLoader.h"

static const int WIDTH = 64;
static const int HEIGHT = 32;

#define BLUE_TEXTURE_PATH ("resources/Textures/element_blue_rectangle_glossy.png")
#define RED_TEXTURE_PATH ("resources/Textures/element_red_rectangle_glossy.png")

Brick::Brick()
{
    //Texture = TextureLoader::LoadTextureFromFile(renderer, BLUE_TEXTURE_PATH);
//    m_LowHealthTexture = TextureLoader::LoadTextureFromFile(renderer, RED_TEXTURE_PATH);
}

void Brick::Draw(Renderer& renderer)
{
    Entity::Draw(renderer);

    bool isLowHealth = m_BrickHealth <= (m_MaxBrickHealth / 2);
//    if (isLowHealth)
//    {
//        SDL_RenderCopyF(renderer, m_LowHealthTexture, nullptr, &Bounds);
//        return;
//    }
//
//    SDL_RenderCopyF(renderer, Texture, nullptr, &Bounds);
}
