#include "robot.h"
#include "humanic.h"
#include "romba.h"
#include "robocop.h"
#include "bulldozer.h"
#include "optimusPrime.h"
#include "world.h"

Romba::Romba(int sequence, int x, int y) : Robot(30,40){ //to define constructor.
    string temp;
    temp = "romba_"+ to_string(sequence);//to create name of robot with using creation number.
    setname(temp);
    this->x = x;
    this->y = y;    
}

int Romba::getType(){ //to define getType function.
    return 1;
}

int Romba::getDamage(){ //to define getDamage function.
        int damage = Robot::getDamage() + Robot::getDamage(); //to call getDamage function.
        return damage;
}