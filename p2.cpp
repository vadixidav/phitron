#include "p2.h"

namespace phi {
    void attract(double coefficient, P2 &a, P2 &b) {
        V2 delta = b.position;
        delta -= a.position;
        double distance = delta.magnitude();
        delta *= coefficient / pow(distance, 3);
        a.acceleration += delta;
        b.acceleration -= delta;
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
