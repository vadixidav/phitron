#ifndef P2_H
#define P2_H

#include "v2.h"

namespace phi {
    struct P2 {
        double inertia;
        V2 position;
        V2 velocity;
        V2 acceleration;
        
        P2() : acceleration(V2(0, 0)) {}
        P2(double inertia) : inertia(inertia), acceleration(V2(0, 0)) {}
        P2(double inertia, V2 position) : inertia(inertia), position(position), acceleration(V2(0, 0)) {}
        P2(double inertia, V2 position, V2 velocity) : inertia(inertia), position(position), velocity(velocity),
           acceleration(V2(0, 0)) {}
        
        //Advance particle and reset acceleration to 0
        void advance() {
            acceleration /= inertia;
            velocity += acceleration;
            position += velocity;
            acceleration = V2(0, 0);
        }
        
        //Add generic force
        void force(const V2 &df) {
            acceleration += df;
        }
        
        //Drag force
        void drag(double coefficient) {
            V2 force = velocity;
            force *= coefficient;
            acceleration -= force;
        }
        
        //Angular force
        void angular(double coefficient, double angle) {
            V2 force(cos(angle), sin(angle));
            force *= coefficient;
            acceleration += force;
        }
        
        //Gravitation around a location
        void gravitate(double coefficient, const V2 &location, double radiusSquared = 0.0);
    };
    
    //Gravitational force
    void attract(double coefficient, P2 &a, P2 &b, double radiusSquared = 0.0);
    
    //Hooke's law with equilibrium point (always use posititve equilibrium
    void spring(double coefficient, double equilibrium, P2 &a, P2 &b);
}

#endif // P2_H

