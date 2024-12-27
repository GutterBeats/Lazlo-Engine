cmake_minimum_required(VERSION 3.30.5)
project(Lazlo_Engine)

set(CMAKE_CXX_STANDARD 23)
enable_language(OBJC)

add_executable(Lazlo_Engine src/main.cpp
        src/core/Renderer.cpp
        src/core/Renderer.h
        src/core/Window.cpp
        src/core/Window.h
        src/core/ApplicationConfig.h
        src/core/Vector2D.h
        src/core/Application.cpp
        src/core/Application.h
        src/core/Logging.h
        src/core/EventSystem.cpp
        src/core/EventSystem.h
        src/core/Event.h)

set(SDLMIXER_VENDORED ON)
set(SDLTTF_VENDORED ON)

add_subdirectory(vendor/SDL)
add_subdirectory(vendor/SDL_image)
add_subdirectory(vendor/SDL_mixer)
add_subdirectory(vendor/SDL_ttf)

target_link_libraries(
        Lazlo_Engine PRIVATE
        SDL3::SDL3
        SDL3_image::SDL3_image
        SDL3_ttf::SDL3_ttf
        SDL3_mixer::SDL3_mixer
)

target_include_directories(
        Lazlo_Engine PRIVATE
        src
        vendor/SDL/include
        vendor/SDL_image/include
        vendor/SDL_mixer/include
        vendor/SDL_ttf
)
