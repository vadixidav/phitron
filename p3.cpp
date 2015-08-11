#include "p3.h"

namespace phi {
    void P3::lorentz(const V3 &field) {
        V3 force(velocity, field);
        acceleration += force;
    }
    
    void P3::gravitate(double coefficient, const V3 &location, double radiusSquared) {
        V3 delta = location;
        delta -= position;
        double distance = delta.magnitudeSquared();
        if (distance < radiusSquared)
            delta *= coefficient / radiusSquared;
        else
            delta *= coefficient / pow(distance, 1.5);
        acceleration += delta;
    }
    
    void P3::spring(double coefficient, double equilibrium, const V3 &location) {
        V3 delta = location;
        delta -= position;
        double k = coefficient * (delta.magnitude() - equilibrium);
        delta.normalize();
        delta *= k;
        acceleration += delta;
    }

    void attract(double coefficient, P3 &a, P3 &b, double radiusSquared) {
        V3 delta = b.position;
        delta -= a.position;
        double distance = delta.magnitudeSquared();
        if (distance < radiusSquared)
            delta *= coefficient / radiusSquared;
        else
            delta *= coefficient / pow(distance, 1.5);
        a.acceleration += delta;
        b.acceleration -= delta;
    }
    
    void lorentz(double coefficient, P3 &a, P3 &b, double radiusSquared) {
        V3 delta = b.position;
        delta -= a.position;
        
        V3 firstcross(a.velocity, delta);
        V3 secondcross(b.velocity, firstcross);
        
        double distance = delta.magnitudeSquared();
        if (distance < radiusSquared)
            secondcross *= coefficient / radiusSquared;
        else
            secondcross *= coefficient / pow(distance, 1.5);
        b.acceleration += secondcross;
        a.acceleration -= secondcross;
    }
    
    void spring(double coefficient, double equilibrium, P3 &a, P3 &b) {
        V3 delta = b.position;
        delta -= a.position;
        double k = coefficient * (delta.magnitude() - equilibrium);
        delta.normalize();
        delta *= k;
        a.acceleration += delta;
        b.acceleration -= delta;
    }
}

