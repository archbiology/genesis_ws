#include "impulse_solver.hpp"

#include "core/creation.hpp"

namespace Genesis {

void ImpulseSolver::solve(std::vector<Collision>& collisions, float dt) {
    // ---------------------------------------
    // Coefficient of restitution (bounciness)
    // ---------------------------------------
    const float restitution = 0.8f;

    // ------------------------------------
    // Base factor for impulse calculations
    // ------------------------------------
    const float baseFactor = 1.0f;

    // -------------------------------------------------
    // Elasticity adjustment factor based on restitution
    // -------------------------------------------------
    const float elasticityFactor = baseFactor + restitution;

    for (Collision& collision : collisions) {
        if (!collision.points.hasCollision) {
            continue;
        }

        // -------------------------------------------------
        // Calculate relative velocity between objA and objB
        // -------------------------------------------------
        Vec3 relativeVelocity = collision.objB->transform.position -
                                collision.objA->transform.position;

        // -------------------------------------------------
        // Calculate the velocity along the collision normal
        // -------------------------------------------------
        float velocityAlongNormal =
            relativeVelocity.dot(collision.points.normal);

        // --------------------------------
        // Skip if objects are moving apart
        // --------------------------------
        if (velocityAlongNormal > 0) {
            continue;
        }

        // ----------------------------------------
        // Calculate the impulse scalar (magnitude)
        // ----------------------------------------
        float impulseMagnitude = -(elasticityFactor)*velocityAlongNormal;
        impulseMagnitude /= (baseFactor / collision.objA->mass +
                             baseFactor / collision.objB->mass);

        // ----------------------------
        // Calculate the impulse vector
        // ----------------------------
        Vec3 impulse = collision.points.normal * impulseMagnitude;

        // -------------------------------------------------
        // Apply the impulse to objA, adjusting its position
        // -------------------------------------------------
        collision.objA->transform.position -=
            impulse * (baseFactor / collision.objA->mass);

        // -------------------------------------------------
        // Apply the impulse to objB, adjusting its position
        // -------------------------------------------------
        collision.objB->transform.position +=
            impulse * (baseFactor / collision.objB->mass);
    }
}

void ImpulseSolver::terminate() {}
}  // namespace Genesis