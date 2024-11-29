# Particle Simulation

This project is a particle simulation built in C++ using SDL2 for graphical rendering. It creates visually dynamic patterns by simulating the motion of particles on the screen. The patterns are affected by trigonometric functions and configurable variables, providing opportunities for creative exploration.

## Features
- Particle-based simulation with dynamic movement.
- Smooth animations using SDL2.
- Configurable parameters that alter particle motion patterns.

## Requirements
To build and run this project, ensure you have the following installed:
- **C++17** or later
- **SDL2** (Simple DirectMedia Layer library)

## File Structure
The project consists of the following key files:
- `main.cpp`: Entry point of the application, handles the main simulation loop and rendering.
- `Screen.h` and `Screen.cpp`: Responsible for managing the screen and drawing pixels.
- `Swarm.h` and `Swarm.cpp`: Manages the collection of particles and updates their state.
- `Particle.h` and `Particle.cpp`: Defines the behavior and properties of individual particles.

## Installation and Setup
1. Install SDL2 development libraries:
   - On Ubuntu/Debian:
     ```bash
     sudo apt-get install libsdl2-dev
     ```
   - On macOS (using Homebrew):
     ```bash
     brew install sdl2
     ```
   - On Windows:
     - Download and install SDL2 from [libsdl.org](https://libsdl.org).

2. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-folder>
   ```

3. Compile the project:
   ```bash
   g++ -std=c++17 -o ParticleSimulation main.cpp Swarm.cpp Particle.cpp Screen.cpp -lSDL2 -lm
   ```

4. Run the application:
   ```bash
   ./ParticleSimulation
   ```

## Usage
- The application displays dynamic patterns created by particle movements.
- Changing variable values in `Swarm.cpp` or `Particle.cpp` can alter the patterns:
    - Modify **speed** and **direction** in `Particle.cpp` to control particle behavior.
    - Adjust **color transitions** in `main.cpp` for different visual effects.

## Libraries Used
- [SDL2](https://www.libsdl.org): For graphics rendering.
- Standard C++ libraries: `iostream`, `cmath`, `cstdlib`.

## Key Configurable Variables
- **`Particle::m_speed`**: Affects particle velocity.
- **`Particle::m_direction`**: Governs the direction of particle motion.
- **Color variables in `main.cpp`**: Change the RGB values for particle colors.

## Example Visualization
This simulation generates vibrant, evolving particle patterns like these:

## Author
Lucas Relva  
São Paulo, Brazil
