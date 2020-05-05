cmake_minimum_required(VERSION 2.8.11)
project(VirusGame)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)
find_package(SDL2 CONFIG REQUIRED)     # check if SDL2     is installed
find_package(sdl2-gfx CONFIG REQUIRED) # check if SDL2_gfx is installed
include_directories(${SDL2_INCLUDE_DIRS})

find_path(SYSTEM_INCLUDE_DIR SDL2/SDL.h)
include_directories(${SYSTEM_INCLUDE_DIR})

add_executable(VirusGame VirusGame.cpp)
target_link_libraries(VirusGame PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2::SDL2_gfx)
