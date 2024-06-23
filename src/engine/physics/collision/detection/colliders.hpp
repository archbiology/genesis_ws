#ifndef genesis_colliders
#define genesis_colliders

#include "math/vec3.hpp"

namespace Genesis {

/*
 * @brief Enum for specifying the type of collider.
 *
 * Define the different types of colliders available.
 *
 * Credits: https://winter.dev/articles/physics-engine#Collision, and ChatGPT.
 */
enum ColliderType { SPHERE, PLANE };

/**
 * @class Collider
 * @brief Base class for all collider types.
 *
 * This class serves as the base for all specific collider types. It contains a
 * type member to distinguish between different kinds of colliders.
 *
 * Credits: https://winter.dev/articles/physics-engine#Collision, and ChatGPT.
 */
class Collider {
   public:
    /**
     * @brief The type of the collider.
     *
     * The type of the collider (e.g., SPHERE or PLANE).
     */
    ColliderType type;
};

/**
 * @brief A spherical collider used for collision detection.
 *
 * This class represents a spherical collider which is defined by a center
 * point and a radius. It is used to detect collisions with other objects.
 *
 * Credits: https://winter.dev/articles/physics-engine#Collision, and ChatGPT.
 */
class SphereCollider : Collider {
   public:
    /**
     * @brief The center of the sphere.
     *
     * It represents the center point of the spherical collider in 3D space.
     */
    Vec3 center;

    /**
     * @brief The radius of the sphere.
     *
     * It represents the radius of the spherical collider.
     */
    float radius;
};

/**
 * @brief A planar collider used for collision detection.
 *
 * This struct represents a planar collider which is defined by a normal vector
 * and a distance from the origin. It is used to detect collisions with other
 * objects.
 *
 * Credits: https://winter.dev/articles/physics-engine#Collision, and ChatGPT.
 */
class PlaneCollider : Collider {
   public:
    /**
     * @brief The normal vector of the plane.
     *
     * This vector represents the direction perpendicular to the plane.
     */
    Vec3 normal;

    /**
     * @brief The distance of the plane from the origin along the normal vector.
     *
     * It represents the distance from the origin to the plane.
     */
    float distance;
};

}  // namespace Genesis

#endif  // genesis_colliders
