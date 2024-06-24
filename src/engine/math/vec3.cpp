#include "vec3.hpp"

namespace Genesis {

// ----------------
// Credits: ChatGPT
// ----------------

Vec3::Vec3() : x(0), y(0), z(0) {}

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

Vec3 Vec3::operator+(const Vec3& other) const {
    return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator+(float scalar) const {
    return Vec3(x + scalar, y + scalar, z + scalar);
}

Vec3 Vec3::operator-(const Vec3& other) const {
    return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 Vec3::operator-(float scalar) const {
    return Vec3(x - scalar, y - scalar, z - scalar);
}

Vec3 Vec3::operator*(const Vec3& other) const {
    return Vec3(x * other.x, y * other.y, z * other.z);
}

Vec3 Vec3::operator*(float scalar) const {
    return Vec3(x * scalar, y * scalar, z * scalar);
}

Vec3 Vec3::operator/(const Vec3& other) const {
    return Vec3(x / other.x, y / other.y, z / other.z);
}

Vec3 Vec3::operator/(float scalar) const {
    return Vec3(x / scalar, y / scalar, z / scalar);
}

Vec3 operator+(float scalar, const Vec3& vec) {
    return Vec3(scalar + vec.x, scalar + vec.y, scalar + vec.z);
}

Vec3 operator-(float scalar, const Vec3& vec) {
    return Vec3(scalar - vec.x, scalar - vec.y, scalar - vec.z);
}

Vec3 operator*(float scalar, const Vec3& vec) {
    return Vec3(scalar * vec.x, scalar * vec.y, scalar * vec.z);
}

Vec3 operator/(float scalar, const Vec3& vec) {
    return Vec3(scalar / vec.x, scalar / vec.y, scalar / vec.z);
}

Vec3& Vec3::operator+=(const Vec3& other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    return *this;
}

Vec3& Vec3::operator+=(float scalar) {
    this->x += scalar;
    this->y += scalar;
    this->z += scalar;
    return *this;
}

Vec3& Vec3::operator-=(const Vec3& other) {
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    return *this;
}

Vec3& Vec3::operator-=(float scalar) {
    this->x -= scalar;
    this->y -= scalar;
    this->z -= scalar;
    return *this;
}

Vec3 Vec3::operator-() const { return Vec3(-x, -y, -z); }

bool Vec3::operator==(const Vec3& other) const {
    // Compare each component
    return std::abs(x - other.x) < EPSILON && std::abs(y - other.y) < EPSILON &&
           std::abs(z - other.z) < EPSILON;
}

float Vec3::dot(const Vec3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

std::ostream& operator<<(std::ostream& os, const Vec3& vec) {
    os << "Vec3(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return os;
}

}  // namespace Genesis
