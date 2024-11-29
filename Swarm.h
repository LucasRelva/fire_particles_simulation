//
// Created by lucas.relva on 29/11/2024.
//

#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

namespace mystf {
    class Swarm final {
        Particle *m_p_particles;
        int last_time;

    public:
        static constexpr int N_PARTICLES = 3000;

        Swarm();
        ~Swarm();

        [[nodiscard]] Particle *get_particles() const { return m_p_particles; }
        void update(int elapsed);
    };
} // mystf

#endif //SWARM_H
