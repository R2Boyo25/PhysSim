#pragma once
#include <vector>
#include <cmath>

namespace vec {
    class Vec3{
        public:
            float x = 0;
            float y = 0;
            float z = 0;

            Vec3(float x, float y, float z);
            Vec3();

            void addVec(Vec3 vec);
            Vec3 clone();
    };    
}