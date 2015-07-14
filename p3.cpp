#include "p3.h"

namespace phi {
    void P3::lorentz(const V3 &field) {
        V3 force(velocity, field);
        acceleration += force;
    }

    void attract(double coefficient, P3 &a, P3 &b) {
        V3 delta = b.position;
        delta -= a.position;
        double distance = delta.magnitude();
        delta *= coefficient / pow(distance, 3);
        a.acceleration += delta;
        b.acceleration -= delta;
    }
    
    void lorentz(double coefficient, P3 &a, P3 &b) {
        V3 delta = b.position;
        delta -= a.position;
        
        V3 firstcross(a.velocity, delta);
        V3 secondcross(b.velocity, firstcross);
        secondcross *= coefficient / pow(delta.magnitude(), 3);
        b.acceleration += secondcross;
        a.acceleration -= secondcross;
    }
}

