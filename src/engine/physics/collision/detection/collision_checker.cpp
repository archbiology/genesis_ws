#ifndef genesis_check_collision
#define genesis_check_collision

#include "collision_checker.hpp"

#include <cmath>

#include "colliders.hpp"
#include "collision_points.hpp"
#include "transform.hpp"

namespace Genesis {

CollisionPoints Test_Sphere_Sphere(const Collider* a, const Transform* ta,
                                   const Collider* b, const Transform* tb) {
    // ---------------------------------
    // Ensure both colliders are spheres
    // ---------------------------------
    if (a->type != ColliderType::SPHERE || b->type != ColliderType::SPHERE) {
        return CollisionPoints();
    }

    // --------------------------------
    // Cast colliders to SphereCollider
    // --------------------------------
    const SphereCollider* sphereA = static_cast<const SphereCollider*>(a);
    const SphereCollider* sphereB = static_cast<const SphereCollider*>(b);

    // -------------------------------------------------------
    // Calculate the vector between the centers of the spheres
    // -------------------------------------------------------
    Vec3 centerA = ta->position + sphereA->center;
    Vec3 centerB = tb->position + sphereB->center;
    Vec3 delta = centerB - centerA;

    // --------------------------------------------------
    // Calculate the squared distance between the centers
    // --------------------------------------------------
    float distSquared =
        delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
    float radiusSum = sphereA->radius + sphereB->radius;
    float radiusSumSquared = radiusSum * radiusSum;

    CollisionPoints points;

    // ----------------------------------
    // Check if the spheres are colliding
    // ----------------------------------
    if (distSquared < radiusSumSquared) {
        float distance = std::sqrt(distSquared);

        // -------------------------
        // Calculate collision depth
        // -------------------------
        points.depth = radiusSum - distance;

        // ---------------------------------------------
        // Calculate collision normal (normalized delta)
        // ---------------------------------------------
        if (distance != 0) {
            points.normal = delta / distance;
        } else {
            // --------------------------------------------
            // If distance is zero, use an arbitrary normal
            // --------------------------------------------
            points.normal = Vec3(1, 0, 0);
        }

        // --------------------------------------------------------
        // Calculate collision points on the surface of each sphere
        // --------------------------------------------------------
        points.a = centerA + points.normal * sphereA->radius;
        points.b = centerB - points.normal * sphereB->radius;

        points.hasCollision = true;
    } else {
        points.hasCollision = false;
    }

    return points;
}

CollisionPoints Test_Sphere_Plane(const Collider* a, const Transform* ta,
                                  const Collider* b, const Transform* tb) {
    // ---------------------------------------------------------------
    // Ensure the first collider is a sphere and the second is a plane
    // ---------------------------------------------------------------
    if (a->type != ColliderType::SPHERE || b->type != ColliderType::PLANE) {
        return CollisionPoints();
    }

    // --------------------------------------------------
    // Cast colliders to SphereCollider and PlaneCollider
    // --------------------------------------------------
    const SphereCollider* sphere = static_cast<const SphereCollider*>(a);
    const PlaneCollider* plane = static_cast<const PlaneCollider*>(b);

    // -------------------------------------
    // Calculate the sphere's world position
    // -------------------------------------
    Vec3 sphereCenter = ta->position + sphere->center;

    // -----------------------------------------------------------------------
    // Calculate the perpendicular distance from the sphere's center to the
    // plane using the dot product between the sphere's center and the plane's
    // normal, then subtracting the plane's distance from the origin.
    // -----------------------------------------------------------------------
    float distanceToPlane = sphereCenter.dot(plane->normal) - plane->distance;

    CollisionPoints points;

    // -----------------------------------------------
    // Check if the sphere is colliding with the plane
    // -----------------------------------------------
    if (std::abs(distanceToPlane) <= sphere->radius) {
        // -----------------------------------------------------------
        // Calculate collision depth
        // Check if the absolute distance from the sphere's center to
        // the plane is less than or equal to the sphere's radius.
        // -----------------------------------------------------------
        points.depth = sphere->radius - std::abs(distanceToPlane);

        // -------------------------------------------------
        // The normal of the collision is the plane's normal
        // -------------------------------------------------
        points.normal = plane->normal;

        // --------------------------------------------------------
        // Calculate the point of collision on the sphere's surface
        // --------------------------------------------------------
        points.a = sphereCenter - plane->normal * distanceToPlane;

        // ----------------------------------------------------------
        // The point of collision on the plane is the same as point a
        // since the plane is considered an infinite flat surface.
        // Set the collision normal to the plane's normal.
        // ----------------------------------------------------------
        points.b = points.a;

        points.hasCollision = true;
    } else {
        points.hasCollision = false;
    }

    return points;
}

using FindContactFunc = CollisionPoints (*)(const Collider*, const Transform*,
                                            const Collider*, const Transform*);

CollisionPoints TestCollision(const Collider* a, const Transform* at,
                              const Collider* b, const Transform* bt) {
    static const FindContactFunc tests[2][2] = {
        // Sphere             Plane
        {Test_Sphere_Sphere, Test_Sphere_Plane},  // Sphere
        {nullptr, nullptr}                        // Plane
    };

    // --------------------------------------------
    // If we are passed a Plane vs Sphere, swap the
    // colliders so it's a Sphere vs Plane
    // --------------------------------------------
    bool swap = b->type > a->type;
    if (swap) {
        std::swap(a, b);
        std::swap(at, bt);
    }

    // ----------------------------------------
    // Now we can dispatch the correct function
    // ----------------------------------------
    CollisionPoints points = tests[a->type][b->type](a, at, b, bt);

    // -----------------------------------------------------
    // if we swapped the order of the colliders, to keep the
    // results consistent, we need to swap the points also.
    // -----------------------------------------------------
    if (swap) {
        std::swap(points.a, points.b);
        points.normal = -points.normal;
    }

    return points;
};

}  // namespace Genesis

#endif  // genesis_check_collision