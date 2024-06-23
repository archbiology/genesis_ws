#include "dynamics_service.hpp"

#include "core/app.hpp"

namespace Genesis {

void DynamicsService::initialize(App* genesis) { this->genesis = genesis; }

void DynamicsService::update() {
    // Credits: https://winter.dev/articles/physics-engine#Dynamics

    float dt = 1;  // FIXME: this must be a parameters or set somewhere else.

    for (auto& creation : genesis->objects) {
        // creation->update();

        // -------------
        // Apply a force
        // -------------
        // creation->force += creation->mass * gravity;
        creation->force = creation->mass * gravity;

        // -----------------------------------
        // Calculate new velocity and position
        // -----------------------------------
        creation->velocity += creation->force / creation->mass * dt;
        creation->position += creation->velocity * dt;

        // --------------------------
        // Reset net force at the end
        // --------------------------
        // creation->force = Vec3(0, 0, 0);
        // std::cout << creation << std::endl;
    }
}

void DynamicsService::terminate() {}

}  // namespace Genesis
