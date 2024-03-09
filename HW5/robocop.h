#ifndef ROBOCOP_H
#define ROBOCOP_H

#include "robot.h"
#include "humanic.h"

class Robocop : public Humanic{
    friend class World; //to define friend class.

    public:
        Robocop(int sequence, int x, int y); //to define constructor.
        ~Robocop(); //to define ddestructor.
        Robocop(World* world, int x, int y); //to define constructor.
        int getType(); //to define getType function.
        int getDamage(); //to define getDamage function.
};

#endif