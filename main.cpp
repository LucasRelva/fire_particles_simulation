#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>

#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace mystf;

int main() {
    srand(time(nullptr));
    Screen screen;

    if (screen.init() == false) {
        cerr << "Failed to initialize screen" << endl;
        return 1;
    }

    Swarm swarm;

    static constexpr int HALF_WIDTH = Screen::SCREEN_WIDTH / 2;
    static constexpr int HALF_HEIGHT = Screen::SCREEN_HEIGHT / 2;

    while (true) {
        // * Draw particles
        const Particle *p_particles = swarm.get_particles();
        int elapsed = SDL_GetTicks();
        swarm.update(elapsed);

        unsigned char green = static_cast<unsigned char>((1 + sin(elapsed * 0.00045)) * 128);
        unsigned char red = static_cast<unsigned char>((1 + sin(elapsed * 0.00056)) * 128);
        unsigned char blue = static_cast<unsigned char>((1 + sin(elapsed * 0.00067)) * 128);

        for (int i = 0; i<Swarm::N_PARTICLES; i++) {
            Particle particle = p_particles[i];
            int x = static_cast<int>((particle.m_x+1) * HALF_WIDTH);
            int y = static_cast<int>(particle.m_y * HALF_WIDTH + HALF_HEIGHT);
            screen.set_pixel(x, y, red, green, blue);
        }

        screen.box_blur();

        // * Draw the screen
        screen.update();

        // * Check for messages/events
        if (screen.process_events() == false) {
            break;
        }
    }

    screen.close();
    return 0;
}
