#ifndef genesis_collision
#define genesis_collision

#include "collision_points.hpp"

namespace Genesis {

class Creation;  // Forward declaration

/**
 * @brief Represents a collision event between two objects in the game engine.
 *
 * It stores information about a collision between two objects
 * (referred to as `objA` and `objB`) and the details of the collision points.
 *
 * Credits: https://winter.dev/articles/physics-engine#Collision, and ChatGPT.
 */
class Collision {
   public:
    /**
     * @brief Pointer to the first object involved in the collision.
     */
    Creation* objA;

    /**
     * @brief Pointer to the second object involved in the collision.
     */
    Creation* objB;

    /**
     * @brief Details of the collision points.
     *
     * It stores detailed information about the collision points, including the
     * furthest points of each object into the other, the normal vector of the
     * collision, and the penetration depth.
     */
    CollisionPoints points;
};

}  // namespace Genesis

#endif  // genesis_collision
