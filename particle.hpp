#pragma once

#include <panda3d/pandaFramework.h>
#include <panda3d/pandaSystem.h>

#include<iostream>
#include "vec.hpp"

extern PandaFramework framework;
extern WindowFramework *window;
extern NodePath Sphere;

namespace particle {
    class Particle {
        private:
            NodePath model;

        public:
            Particle();
            Particle(vec::Vec3 pos, vec::Vec3 vel, double size);
            void move();

            vec::Vec3 pos    = vec::Vec3(0, 0, 0);
            vec::Vec3 vel    = vec::Vec3(0, 0, 0);
            double    size   = 0;
            double    mass   = 0;
            int       charge = 0;
    };
}