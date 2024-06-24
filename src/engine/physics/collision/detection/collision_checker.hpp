#ifndef genesis_collision_checker
#define genesis_collision_checker

#include "colliders.hpp"
#include "collision_points.hpp"
#include "transform.hpp"

namespace Genesis {

/**
 * @brief Tests for collision between two spheres.
 *
 * @param a The first sphere's collider.
 * @param ta The transform of the first sphere.
 * @param b The second sphere's collider.
 * @param tb The transform of the second sphere.
 * @return CollisionPoints The details of the collision.
 *
 * Credits: https://winter.dev/articles/physics-engine#Collision, and ChatGPT.
 */
CollisionPoints Test_Sphere_Sphere(const Collider* a, const Transform* ta,
                                   const Collider* b, const Transform* tb);

/**
 * @brief Tests for collision between a sphere and a plane.
 *
 * @param a The sphere's collider.
 * @param ta The transform of the sphere.
 * @param b The plane's collider.
 * @param tb The transform of the plane.
 * @return CollisionPoints The details of the collision.
 *
 * Credits: https://winter.dev/articles/physics-engine#Collision, and ChatGPT.
 */
CollisionPoints Test_Sphere_Plane(const Collider* a, const Transform* ta,
                                  const Collider* b, const Transform* tb);

CollisionPoints TestCollision(const Collider* a, const Transform* at,
                              const Collider* b, const Transform* bt);
}  // namespace Genesis

#endif  // genesis_collision_checker