#include <iostream>
#include "Vector3.hpp"

namespace gs {
    
    Vector3::Vector3(const Vector3& v): x(v.x), y(v.y), z(v.z) {}

    Vector3& Vector3::operator=(const Vector3& v) {
        x = v.x;
        y = v.y;
        z = v.z;

        return *this;
    }

    void Vector3::operator+=(const Vector3& v) {
        x += v.x;
        y += v.y;
        z += v.z;
    }

    Vector3 Vector3::operator+(const Vector3& v) {
        return Vector3(x + v.x,
                       y + v.y,
                       z + v.z);
    }

    void Vector3::operator-=(const Vector3& v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
    }

    Vector3 Vector3::operator-(const Vector3& v) {
        return Vector3(x - v.x,
                       y - v.y,
                       z - v.z);
    }

    void Vector3::operator*=(const float s) {
        x *= s;
        y *= s;
        z *= s;
    }

    Vector3 Vector3::operator*(const float s) const {
        return Vector3(x * s,
                       y * s,
                       z * s);
    }

    void Vector3::operator/=(const float s) {
        x /= s;
        y /= s;
        z /= s;
    }

    Vector3 Vector3::operator/(const float s) const {
        return Vector3(x / s,
                       y / s,
                       z / s);
    }

    float Vector3::operator*(const Vector3& v) const {
        return x*v.x + y*v.y + z*v.z;
    }

    float Vector3::dot(const Vector3& v) const {
        return x*v.x + y*v.y + z*v.z;
    }

    Vector3 Vector3::cross(const Vector3& v) const {
        return Vector3(y * v.z - z * v.y,
                       z * v.x - x * v.z,
                       x * v.y - y * v.x);
    }

    void Vector3::operator%=(const Vector3& v) {
        *this = cross(v);
    }

    Vector3 Vector3::operator%(const Vector3& v) const {
        return Vector3(y * v.z - z * v.y,
                       z * v.x - x * v.z,
                       x * v.y - y * v.x);
    }

    void Vector3::Show() {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }

}