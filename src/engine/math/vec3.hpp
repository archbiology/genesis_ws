#ifndef genesis_math_vec3
#define genesis_math_vec3

#include <iostream>

namespace Genesis {

/**
 * @brief 3D class with 3 floats for x, y, z or i + j + k.
 *
 * Credits: https://winter.dev/articles/physics-engine and ChatGPT
 */
class Vec3 {
   public:
    float x, y, z;

    Vec3();

    /**
     * @brief Constructor to initialize the vector.
     * @param x X component.
     * @param y Y component.
     * @param z Z component.
     */
    Vec3(float x, float y, float z);

    /**
     * @brief Addition operator for vector-vector addition.
     * @param other The other vector to add.
     * @return A new vector that is the sum of this vector and the other vector.
     */
    Vec3 operator+(const Vec3& other) const;

    /**
     * @brief Addition operator for vector-scalar addition.
     * @param scalar The scalar value to add.
     * @return A new vector that is the sum of this vector and the scalar.
     */
    Vec3 operator+(float scalar) const;

    /**
     * @brief Subtraction operator for vector-vector subtraction.
     * @param other The other vector to subtract.
     * @return A new vector that is the difference of this vector and the other
     * vector.
     */
    Vec3 operator-(const Vec3& other) const;

    /**
     * @brief Subtraction operator for vector-scalar subtraction.
     * @param scalar The scalar value to subtract.
     * @return A new vector that is the difference of this vector and the
     * scalar.
     */
    Vec3 operator-(float scalar) const;

    /**
     * @brief Multiplication operator for vector-vector multiplication.
     * @param other The other vector to multiply.
     * @return A new vector that is the product of this vector and the other
     * vector.
     */
    Vec3 operator*(const Vec3& other) const;

    /**
     * @brief Multiplication operator for vector-scalar multiplication.
     * @param scalar The scalar value to multiply.
     * @return A new vector that is the product of this vector and the scalar.
     */
    Vec3 operator*(float scalar) const;

    /**
     * @brief Division operator for vector-vector division.
     * @param other The other vector to divide.
     * @return A new vector that is the quotient of this vector and the other
     * vector.
     */
    Vec3 operator/(const Vec3& other) const;

    /**
     * @brief Division operator for vector-scalar division.
     * @param scalar The scalar value to divide.
     * @return A new vector that is the quotient of this vector and the scalar.
     */
    Vec3 operator/(float scalar) const;

    /**
     * @brief Friend function for scalar addition on the left.
     * @param scalar The scalar value to add.
     * @param vec The vector to add.
     * @return A new vector that is the sum of the scalar and the vector.
     */
    friend Vec3 operator+(float scalar, const Vec3& vec);

    /**
     * @brief Friend function for scalar subtraction on the left.
     * @param scalar The scalar value to subtract.
     * @param vec The vector to subtract.
     * @return A new vector that is the difference of the scalar and the vector.
     */
    friend Vec3 operator-(float scalar, const Vec3& vec);

    /**
     * @brief Friend function for scalar multiplication on the left.
     * @param scalar The scalar value to multiply.
     * @param vec The vector to multiply.
     * @return A new vector that is the product of the scalar and the vector.
     */
    friend Vec3 operator*(float scalar, const Vec3& vec);

    /**
     * @brief Friend function for scalar division on the left.
     * @param scalar The scalar value to divide.
     * @param vec The vector to divide.
     * @return A new vector that is the quotient of the scalar and the vector.
     */
    friend Vec3 operator/(float scalar, const Vec3& vec);

    /**
     * @brief Overloaded += operator to add another Vec3 to this Vec3.
     * @param other The other vector to add.
     * @return A reference to this Vec3 after the addition.
     */
    Vec3& operator+=(const Vec3& other);

    /**
     * @brief Overloaded += operator to add a float to this Vec3.
     * @param scalar The float value to add.
     * @return A reference to this Vec3 after the addition.
     */
    Vec3& operator+=(float scalar);

    /**
     * @brief Output stream operator for printing the vector.
     * @param os The output stream.
     * @param vec The vector to print.
     * @return The output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Vec3& vec);
};

}  // namespace Genesis

#endif  // genesis_math_vec3
