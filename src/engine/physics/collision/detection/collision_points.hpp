#ifndef genesis_collision_points
#define genesis_collision_points

#include "math/vec3.hpp"

namespace Genesis {

/**
 * @class CollisionPoints
 * @brief A class to represent the points of collision between two objects.
 *
 * This class contains information about the collision points, the normal vector
 * at the point of collision, and the depth of penetration.
 *
 * Credits: https://winter.dev/articles/physics-engine#Collision, and ChatGPT.
 */

class CollisionPoints {
   public:
    /**
     * @brief Furthest point of object A into object B.
     *
     * This is the point on object A that is deepest into object B during a
     * collision.
     */
    Vec3 a;

    /**
     * @brief Furthest point of object B into object A.
     *
     * This is the point on object B that is deepest into object A during a
     * collision.
     */
    Vec3 b;

    /**
     * @brief B – A normalized. Normal vector from point A to point B.
     *
     * This vector represents the direction from the point on object A to the
     * point on object B where the collision is deepest. It is normalized,
     * meaning it has a length of 1.
     *
     * A normal vector in geometry is a vector that is perpendicular
     * (at a 90-degree angle) to a surface or a line.
     *
     * Imagine a flat, horizontal piece of paper. Place a pencil standing
     * upright on the paper. The pencil represents the normal vector because it
     * is perpendicular (90 degrees) to the surface of the paper.
     * It is a vertical vector pointing directly up or down.
     */
    Vec3 normal;

    /**
     * @brief Length of B – A. Depth of penetration from point A to point B.
     *
     * This value represents the distance that object A has penetrated into
     * object B. It is the length of the vector from point A to point B.
     */
    float depth;

    /**
     * @brief Indicates whether a collision has occurred.
     *
     * This boolean value is true if a collision has been detected, and false
     * otherwise.
     */
    bool hasCollision = false;
};

}  // namespace Genesis

#endif  // genesis_collision_points
