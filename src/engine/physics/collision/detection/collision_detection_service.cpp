#include "collision_detection_service.hpp"

#include "collision_checker.hpp"
#include "collision_points.hpp"
#include "core/app.hpp"

namespace Genesis {

void CollisionDetectionService::initialize(App* genesis) {
    this->genesis = genesis;
}

void CollisionDetectionService::update() {
    // Credits: https://winter.dev/articles/physics-engine#Dynamics

    float dt = 1;  // FIXME: this must be a parameters.

    for (auto& a : genesis->objects) {
        for (auto& b : genesis->objects) {
            if (a == b) break;

            if (!a->collider || !b->collider) continue;

            CollisionPoints points = TestCollision(a->collider, &a->transform,
                                                   b->collider, &b->transform);

            if (points.hasCollision)
                genesis->collisions.emplace_back(a, b, points);
        }
    }
}

void CollisionDetectionService::terminate() {}

}  // namespace Genesis
