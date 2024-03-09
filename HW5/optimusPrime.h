#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H

#include "robot.h"
#include "humanic.h"

class Optimusprime : public Humanic{
    friend class World; //to define friend class.

    public:
        Optimusprime(int sequence, int x, int y); //to define constructor.
        Optimusprime(World* world, int x, int y); //to define constructor.
        int getType(); //to define getType function.
        int getDamage(); //to define getDamage function.

};




#endif