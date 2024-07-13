//
// Created by Anthony Lesch on 7/7/24.
//

#pragma once

#include <string>
#include "Renderer.h"

class SDL_Texture;

/*
 * Utility class for loading textures. A call to Initialize() must be made before the class can start loading textures.
 */
class TextureLoader final
{
public:

    /*
     * Initializes the texture loading system.
     * */
    static void Initialize();

    /*
     * Exits the texture loading system and cleans up.
     * */
    static void Exit();

    /*
     * Loads a texture at the provided file path using the renderer. The texture loaded must be freed using SDL_DestroyTexture().
     * */
    static SDL_Texture* LoadTextureFromFile(Renderer* renderer, const std::string& filePath);
};
