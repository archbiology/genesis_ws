#include "collision_response_service.hpp"

#include "core/app.hpp"

namespace Genesis {

void CollisionResponseService::initialize(App* genesis) {
    this->genesis = genesis;
}

void CollisionResponseService::update() {
    float dt = 1;  // FIXME: this must be a parameters.
    int count = 1;

    if (genesis->collisions.empty()) return;

    for (auto& solver : genesis->solvers) {
        solver->solve(genesis->collisions, dt);
    }
}

void CollisionResponseService::terminate() {}

}  // namespace Genesis
