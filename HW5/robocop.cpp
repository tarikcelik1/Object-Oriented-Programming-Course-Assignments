#include "robot.h"
#include "humanic.h"
#include "romba.h"
#include "robocop.h"
#include "bulldozer.h"
#include "optimusPrime.h"
#include "world.h"


Robocop::Robocop(int sequence, int x, int y) : Humanic(30,40){ //to define constructor.
    string temp;
    temp = "robocop_"+ to_string(sequence); //to create name of robot with using creation number.
    setname(temp);
    this->x = x;
    this->y = y;    
}

Robocop::~Robocop() {} //to define destructor.

int Robocop::getType(){ //to define getType function.
    return 3;
}

int Robocop::getDamage(){ //to define getDamage function.
        int damage = Humanic::getDamage(); //to call getDamage function.
        return damage;

}