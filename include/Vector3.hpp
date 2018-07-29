#ifndef Vector3_H
#define Vector3_H

namespace gs {

    class Vector3 {
        public:
            // Constructors
            Vector3(): x(0.0), y(0.0), z(0.0) {}
            Vector3(float x, float y, float z):
                x(x), y(y), z(z) {}

            // Destructor
            virtual ~Vector3() {}

            // Copy constructors
            Vector3(const Vector3& v);
            Vector3& operator=(const Vector3& v);

            // Operator overloads
            void operator+=(const Vector3& v);
            void operator-=(const Vector3& v);
            void operator/=(const float s);
            Vector3 operator+(const Vector3& v);
            Vector3 operator-(const Vector3& v);
            Vector3 operator/(const float s) const;

            // Scalar product
            void operator*=(const float s);
            Vector3 operator*(const float s) const;

            // Dot product
            float operator*(const Vector3& v) const;
            float dot(const Vector3& v) const;

            // Cross product
            Vector3 cross(const Vector3& v) const;
            void operator%=(const Vector3& v);
            Vector3 operator%(const Vector3& v) const;

            void Show();
            
            // Vector components
            float x;
            float y;
            float z;
    };

}

#endif