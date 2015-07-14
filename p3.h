#ifndef P3_H
#define P3_H

#include "v3.h"

namespace phi {
    struct P3 {
        double inertia;
        V3 position;
        V3 velocity;
        V3 acceleration;
        
        P3() : acceleration(V3(0, 0, 0)) {}
        P3(double inertia) : inertia(inertia), acceleration(V3(0, 0, 0)) {}
        P3(double inertia, V3 position) : inertia(inertia), position(position), acceleration(V3(0, 0, 0)) {}
        P3(double inertia, V3 position, V3 velocity) : inertia(inertia), position(position), velocity(velocity),
           acceleration(V3(0, 0, 0)) {}
        
        //Advance particle and reset acceleration to 0
        void advance() {
            acceleration /= inertia;
            velocity += acceleration;
            position += velocity;
            acceleration = V3(0, 0, 0);
        }
        
        //Add generic force
        void force(const V3 &df) {
            acceleration += df;
        }
        
        //Drag force
        void drag(double coefficient) {
            V3 force = velocity;
            force *= coefficient;
            acceleration -= force;
        }
        
        //Lorentz force
        void lorentz(const V3 &field);
    };
    
    //Gravitational force
    void attract(double coefficient, P3 &a, P3 &b);
    
    //Lorentz force between two particles
    void lorentz(double coefficient, P3 &a, P3 &b);
    
    //Hooke's law with equilibrium point (always use posititve equilibrium
    void spring(double coefficient, double equilibrium, P3 &a, P3 &b);
}

#endif // P3_H

