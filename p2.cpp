#include "p2.h"

namespace phi {
    void attract(double coefficient, P2 &a, P2 &b, double radiusSquared) {
        V2 delta = b.position;
        delta -= a.position;
        double distance = delta.magnitudeSquared();
        if (distance < radiusSquared)
            delta *= coefficient / radiusSquared;
        else
            delta *= coefficient / pow(distance, 1.5);
        a.acceleration += delta;
        b.acceleration -= delta;
    }
    
    void P2::gravitate(double coefficient, const V2 &location, double radiusSquared) {
        V2 delta = location;
        delta -= position;
        double distance = delta.magnitudeSquared();
        if (distance < radiusSquared)
            delta *= coefficient / radiusSquared;
        else
            delta *= coefficient / pow(distance, 1.5);
        acceleration += delta;
    }
    
    void spring(double coefficient, double equilibrium, P2 &a, P2 &b) {
        V2 delta = b.position;
        delta -= a.position;
        double k = coefficient * (delta.magnitude() - equilibrium);
        delta.normalize();
        delta *= k;
        a.acceleration += delta;
        b.acceleration -= delta;
    }
}
