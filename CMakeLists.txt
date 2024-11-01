# Minimum CMake version required 
cmake_minimum_required(VERSION 3.10)

# Project name & version
project(PenguinGame VERSION 0.1)

# Specify C Standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

# Include directories
include_directories(

    )

# Source files
set(SOURCES
    game.c

    Board/board.c
    Board/gaussian.c
    Board/perlin_gen.c
    Board/move_player.c

    Placement/heat_based.c
)

# Add executable target
add_executable(game ${SOURCES})

# Set output directory
set_target_properties(game PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Link math library
target_link_libraries(game m)
