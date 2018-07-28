#include "Vector3.hpp"

namespace gs {
    
    Vector3::Vector3(const Vector3& v): x(v.x), y(v.y), z(v.z) {}

    Vector3& Vector3::operator=(const Vector3& v) {
        x = v.x;
        y = v.y;
        z = v.z;

        return *this;
    }

}