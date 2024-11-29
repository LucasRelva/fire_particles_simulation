//
// Created by lucas.relva on 29/11/2024.
//1

#include "Swarm.h"

namespace mystf {
    Swarm::Swarm() {
        m_p_particles = new Particle[N_PARTICLES];
        last_time = 0;
    }

    Swarm::~Swarm() {
        delete[] m_p_particles;
    }

    void Swarm::update(int elapsed) {
        int interval = elapsed - last_time;

        for (int i = 0; i < N_PARTICLES; i++) {
            m_p_particles[i].update(interval);
        }

        last_time = elapsed;
    }
} // mystf
