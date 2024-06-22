#include "vec3.hpp"

namespace Genesis {

Vec3::Vec3() : x(0), y(0), z(0) {}

Vec3::Vec3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

}  // namespace Genesis
