#ifndef HUMANIC_H
#define HUMANIC_H

#include "robot.h"

class Humanic : public Robot{
    friend class World; //to define friend class.

    public:
        Humanic(int strength,int hitpoints);//to define constructor.
        Humanic(World* world, int x, int y);//to define constructor.
        virtual int getType() = 0;  //to define getType function.
        virtual int getDamage() = 0; //to define getDamage function.

};


#endif