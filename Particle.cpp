//
// Created by lucas.relva on 29/11/2024.
//

#include <cstdlib>

#include "Particle.h"

#include <math.h>

namespace mystf {
    Particle::Particle() {
        init();
    }

    void Particle::init() {
        m_x = 0;
        m_y = 0;

        // * change the PI'S values to change how the particles circulates
        // m_direction = 2 * M_1_PI * rand()/RAND_MAX;
        // m_direction = 2 * M_2_PI * rand()/RAND_MAX;
        m_direction = 2 * M_PI * rand()/RAND_MAX;

        m_speed = 0.8 * rand()/RAND_MAX;

        m_speed *= m_speed;
        m_speed = m_speed/2;
    }


    void Particle::update(int interval) {
        m_direction += interval * 0.0005;

        double x_speed = m_speed * cos(m_direction);
        double y_speed = m_speed * sin(m_direction);

        m_x += x_speed * interval / 10.0;
        m_y += y_speed * interval / 10.0;

        if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
            init();
        }
    }

    Particle::~Particle() = default;
} // mystf
