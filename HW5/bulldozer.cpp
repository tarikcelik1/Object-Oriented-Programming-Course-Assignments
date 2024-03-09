#include "robot.h"
#include "humanic.h"
#include "romba.h"
#include "robocop.h"
#include "bulldozer.h"
#include "optimusPrime.h"
#include "world.h"


Bulldozer::Bulldozer(int sequence, int x, int y) : Robot(30,40){ //to define constructor.
    string temp;
    temp = "bulldozer_"+ to_string(sequence); //to create name of robot with using creation number.
    setname(temp);
    this->x = x;
    this->y = y;    
}

Bulldozer::~Bulldozer() {} //to define destructor.


int Bulldozer::getType(){ //to define getType function.
    return 2;
}

int Bulldozer::getDamage(){ //to define getDamage function.
        int damage = Robot::getDamage(); //to call getDamage function.
        return damage;
}
