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

            // Copy Constructors
            Vector3(const Vector3& v);
            Vector3& operator=(const Vector3& v);
            
            // Vector components
            float x;
            float y;
            float z;
    };

}

#endif