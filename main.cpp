#include<panda3d/pandaFramework.h>
#include<panda3d/pandaSystem.h>

#include<panda3d/genericAsyncTask.h>
#include<panda3d/asyncTaskManager.h>
#include<panda3d/ambientLight.h>

#include<vector>
#include"particle.hpp"

using namespace std;

NodePath Sphere;
PandaFramework framework;
WindowFramework *window;
PT(AsyncTaskManager) taskMgr = AsyncTaskManager::get_global_ptr();
PT(ClockObject) globalClock = ClockObject::get_global_clock();
vector<particle::Particle> particles;
NodePath camera;
//PT(AmbientLight) alight;

AsyncTask::DoneStatus MainTask(GenericAsyncTask *task, void *data) {
    for (auto p : particles) {
        p.move();
    }

    return AsyncTask::DS_cont;
}

void load() {
    Sphere = window->load_model(framework.get_models(), "models/sphere.bam");

    //alight->set_color({0.2, 0.2, 0.2, 1});
    //window->get_render().set_light(window->get_render().attach_new_node(alight));

    camera = window->get_camera_group();
    window->setup_trackball();
    camera.set_pos(20, 20, 20);
    camera.look_at(0, 0, 0);

    particles.push_back(particle::Particle(vec::Vec3(-20,0,0), vec::Vec3(0,0.5,0), 1));
    particles.push_back(particle::Particle(vec::Vec3(20,0,0), vec::Vec3(0,-0.5,0), 1));
}

int main(int argc, char *argv[]) {
    
    framework.open_framework(argc, argv);

    framework.set_window_title("Physics Sim");
    window = framework.open_window();

    load();

    taskMgr->add(new GenericAsyncTask("MainLoop", &MainTask, nullptr));

    framework.main_loop();
    framework.close_framework();
    return (0);
}