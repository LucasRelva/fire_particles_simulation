//
// Created by lucas.relva on 29/11/2024.
//

#ifndef PARTICLE_H
#define PARTICLE_H

namespace mystf {
    struct Particle final {
        double m_x;
        double m_y;

        Particle();
        ~Particle();
        void update(int interval);

    private:
        double m_speed;
        double m_direction;
        void init();
    };
} // mystf

#endif //PARTICLE_H
