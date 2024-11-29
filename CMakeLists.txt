cmake_minimum_required(VERSION 3.15)

project(cpp_course_fire_particles)

set(CMAKE_CXX_STANDARD 20)

# Specify SDL2 paths
set(SDL2_DIR C:/Users/lucas.relva/libs/SDL2-2.30.9/x86_64-w64-mingw32)

# Add include directories for SDL2
include_directories(${SDL2_DIR}/include)

# Add SDL2 library directory
link_directories(${SDL2_DIR}/lib)

# Add the executable
add_executable(cpp_course_fire_particles main.cpp
        Screen.cpp
        Screen.h
        Particle.cpp
        Particle.h
        Swarm.cpp
        Swarm.h)

# Add SDL2 definitions
target_compile_definitions(cpp_course_fire_particles PRIVATE SDL_MAIN_HANDLED)

# Link SDL2 libraries
target_link_libraries(cpp_course_fire_particles PRIVATE SDL2main SDL2)

