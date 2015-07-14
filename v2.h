#ifndef V2_H
#define V2_H

#include <cmath>

namespace phi {
    //2 dimensional vector
    struct V2 {
        double x;
        double y;
        
        V2() {}
        V2(double x, double y) : x(x), y(y) {}
        
        //Scalar multiply
        void operator*=(double o) {
            x *= o;
            y *= o;
        }
        //Scalar divide
        void operator/=(double o) {
            x /= o;
            y /= o;
        }
        //Vector add
        void operator+=(const V2 &o) {
            x += o.x;
            y += o.y;
        }
        //Vector subtract
        void operator-=(const V2 &o) {
            x -= o.x;
            y -= o.y;
        }
        //Vector dot product
        double operator*(const V2 &o) {
            return x * o.x + y * o.y;
        }
        double magnitudeSquared() {
            return x * x + y * y;
        }
        double magnitude() {
            return std::sqrt(magnitudeSquared());
        }
        void normalize() {
            double mag = magnitude();
            x /= mag;
            y /= mag;
        }
    };
}

#endif // V2_H

