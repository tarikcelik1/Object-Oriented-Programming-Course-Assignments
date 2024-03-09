#ifndef ROMBA_H
#define ROMBA_H

#include "robot.h"
class Romba : public Robot{
    friend class World; //to define friend class.

    public:
        Romba(int sequence,int x, int y);//to define constructor.
        Romba(World* world, int x, int y); //to define constructor.
        int getType(); //to define getType function.
        int getDamage();//to define getDamage function.
};



#endif