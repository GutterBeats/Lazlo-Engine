cmake_minimum_required(VERSION 3.28)
project(Lazlo_Engine)

set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(Lazlo_Engine main.cpp
        include/Game.h
        src/Game.cpp
        include/Player.h
        src/Entities/Player.cpp
        include/Brick.h
        src/Entities/Brick.cpp
        include/Ball.h
        src/Entities/Ball.cpp
        src/Utilities/TextureLoader.cpp
        include/TextureLoader.h
        include/Keyboard.h
        src/Core/Keyboard.cpp
        include/BrickManager.h
        src/Utilities/BrickManager.cpp
        include/Physics.h
        include/Entity.h
        src/Entities/Entity.cpp
        include/ECS.h
        src/Core/ECS.cpp
        include/Component.h
        src/Components/Component.cpp
        include/Renderer.h
        src/Core/Renderer.cpp
        include/Window.h
        src/Core/Window.cpp
        include/MovementComponent.h
        src/Components/MovementComponent.cpp
        src/Components/SpriteComponent.cpp
        include/SpriteComponent.h
        src/Components/CollisionComponent.cpp
        include/CollisionComponent.h
        include/Types.h
)

add_custom_target(CopyResources
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources
)
add_dependencies(Lazlo_Engine CopyResources)

# Variables storing SDL Framework locations
set(SDL2
    /Library/Frameworks/SDL2.framework)

set(SDL2_image
    /Library/Frameworks/SDL2_image.framework)

set(SDL2_ttf
    /Library/Frameworks/SDL2_ttf.framework)

set(SDL2_mixer
    /Library/Frameworks/SDL2_mixer.framework)

target_link_libraries(
        Lazlo_Engine PRIVATE
        ${SDL2}/Versions/A/SDL2
        ${SDL2_image}/Versions/A/SDL2_image
        ${SDL2_ttf}/Versions/A/SDL2_ttf
        ${SDL2_mixer}/Versions/A/SDL2_mixer
)

target_include_directories(
        Lazlo_Engine PRIVATE
        ${SDL2}/Versions/A/Headers
        ${SDL2_image}/Versions/A/Headers
        ${SDL2_ttf}/Versions/A/Headers
        ${SDL2_mixer}/Versions/A/Headers
)
