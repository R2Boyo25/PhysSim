#include "vec.hpp"

namespace vec {
    Vec3::Vec3(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vec3::Vec3(){
        /*this->x = 0;
        this->y = 0;
        this->z = 0;*/
    }
    
    void Vec3::addVec(Vec3 vec) {
        this->x += vec.x;
        this->y += vec.y;
        this->z += vec.z;
    }

    Vec3 Vec3::clone() {
        return Vec3(this->x, this->y, this->z);
    }
}