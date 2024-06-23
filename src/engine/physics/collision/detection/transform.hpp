#ifndef genesis_physics_transform
#define genesis_physics_transform

#include "math/vec3.hpp"

namespace Genesis {

/**
 * @class Transform
 * @brief Describes an object's location and orientation in 3D space.
 *
 * The Transform class represents the position, scale, and rotation of an object
 * in 3D space. This is commonly used in graphics and physics simulations to
 * determine how objects are placed, resized, and rotated within a scene.
 *
 * Credits: https://winter.dev/articles/physics-engine#Collision, and ChatGPT.
 */
class Transform {
   public:
    /**
     * @brief The position of the object in 3D space.
     *
     * This vector represents the coordinates of the object in the x, y, and z
     * axes.
     */
    Vec3 position;

    /**
     * @brief The scale of the object in 3D space.
     *
     * This vector represents the scaling factors along the x, y, and z axes.
     * Scaling changes the size of the object.
     */
    Vec3 scale;

    /**
     * @brief The rotation of the object in 3D space.
     *
     * This vector represents the rotation angles around the x, y, and z axes,
     * typically in degrees or radians. Rotation changes the orientation of the
     * object.
     */
    Vec3 rotation;
};

}  // namespace Genesis

#endif  // genesis_physics_transform
