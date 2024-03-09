#ifndef BULLDOZER_H
#define BULLDOZER_H

#include "robot.h"

class Bulldozer : public Robot{
    friend class World; //to define friend class.

    public:
        Bulldozer(int sequence, int x, int y); //to define constructor.
        ~Bulldozer(); //to define ddestructor.
        Bulldozer(World* world, int x, int y); //to define constructor.
        int getType(); //to define getType function.
        int getDamage(); //to define getDamage function. 
};


#endif