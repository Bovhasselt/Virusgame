cmake_minimum_required(VERSION 2.8.11)
project(VirusGame)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)
find_package(SDL2 REQUIRED)     # check if SDL2     is installed
find_package(SDL2_gfx REQUIRED) # check if SDL2_gfx is installed
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(VirusGame VirusGame.cpp)
target_link_libraries(VirusGame LINK_PUBLIC SDL2::Main SDL2::GFX)
