#include "particle.hpp"

namespace particle {
    Particle::Particle(){

    }

    Particle::Particle(vec::Vec3 pos, vec::Vec3 vel, double size) {
        this->pos  = pos.clone();
        this->vel  = vel.clone();
        this->size = size;

        // load model
        this->model = window->load_model(framework.get_models(), "models/sphere.bam");
        
        // scale and move model
        this->model.set_scale(size);
        this->model.set_pos(this->pos.x, this->pos.y, this->pos.z);

        // add model to render
        this->model.reparent_to(window->get_render());
    }

    void Particle::move() {
        this->pos.addVec(this->vel);
        this->model.set_pos(this->pos.clone().x, this->pos.clone().y, this->pos.clone().z);
        //this->model.reparent_to(window->get_render());
        std::cout << "X " << this->pos.x << " Y " << this->pos.y << " Z " << this->pos.z << std::endl;
    }
} 