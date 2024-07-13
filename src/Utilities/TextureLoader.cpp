//
// Created by Anthony Lesch on 7/7/24.
//

#include "TextureLoader.h"

#include <SDL_image.h>

static const int FLAGS = IMG_INIT_JPG | IMG_INIT_PNG;

void TextureLoader::Initialize()
{
    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        SDL_Log("Could not initialize IMG Library for PNG: %s", IMG_GetError());
    }

    if ((IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG) != IMG_INIT_JPG)
    {
        SDL_Log("Could not initialize IMG Library for JPG: %s", IMG_GetError());
    }
}

SDL_Texture* TextureLoader::LoadTextureFromFile(Renderer* renderer, const std::string& filePath)
{
    if ((IMG_Init(0) & FLAGS) != FLAGS)
    {
        SDL_Log("The texture loading system has not been initialized.");
        return nullptr;
    }

    SDL_Texture* texture = IMG_LoadTexture(renderer->GetRenderer(), filePath.c_str());
    if (texture == nullptr)
    {
        SDL_Log("Could not load texture! (%s): %s", filePath.c_str(), IMG_GetError());
    }

    return texture;
}

void TextureLoader::Exit()
{
    IMG_Quit();
}
