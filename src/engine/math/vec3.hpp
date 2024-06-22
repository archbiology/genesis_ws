#ifndef genesis_math_vec3
#define genesis_math_vec3

namespace Genesis {

/**
 * @brief 3D class with 3 floats for x, y, z or i + j + k.
 *
 * Credits: https://winter.dev/articles/physics-engine
 */
class Vec3 {
   public:
    float x, y, z;

    Vec3();

    Vec3(float x, float y, float z);
};

}  // namespace Genesis

#endif  // genesis_math_vec3
