#ifndef V3_H
#define V3_H

#include <cmath>

namespace phi {
    //3 dimensional vector
    struct V3 {
        double x;
        double y;
        double z;
        
        V3() {}
        V3(double x, double y, double z) : x(x), y(y), z(z) {}
        
        //Cross product constructor
        V3(const V3 &a, const V3 &b) {
            this->cross(a, b);
        }
        //Scalar multiply
        void operator*=(double o) {
            x *= o;
            y *= o;
            z *= o;
        }
        //Scalar divide
        void operator/=(double o) {
            x /= o;
            y /= o;
            z /= o;
        }
        //Vector add
        void operator+=(const V3 &o) {
            x += o.x;
            y += o.y;
            z += o.z;
        }
        //Vector subtract
        void operator-=(const V3 &o) {
            x -= o.x;
            y -= o.y;
            z -= o.z;
        }
        //Vector dot product
        double operator*(const V3 &o) {
            return x * o.x + y * o.y + z * o.z;
        }
        //Vector cross product (puts result into this vector)
        void cross(const V3 &a, const V3 &b) {
            x = a.y * b.z - a.z * b.y;
            y = a.z * b.x - a.x * b.z;
            z = a.x * b.y - a.y * b.x;
        }
        double magnitudeSquared() {
            return x * x + y * y + z * z;
        }
        double magnitude() {
            return std::sqrt(magnitudeSquared());
        }
        void normalize() {
            double mag = magnitude();
            x /= mag;
            y /= mag;
            z /= mag;
        }
    };
}

#endif // V3_H

