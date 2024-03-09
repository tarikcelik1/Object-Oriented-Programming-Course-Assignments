#include "robot.h"
#include "humanic.h"
#include "romba.h"
#include "robocop.h"
#include "bulldozer.h"
#include "optimusPrime.h"
#include "world.h"
#include "optimusPrime.h"


Humanic :: Humanic(int strength , int hitpoints):Robot(strength,hitpoints){}

int Humanic :: getDamage(){ //to define getDamage function.
    int damage = Robot::getDamage();
    if(rand() % 10 == 5){ //to create %10 random chance to tactical nuke attack.
        cout << "Tactical nuke attack!" << endl;
        damage += 50;
    }
    return damage;
}