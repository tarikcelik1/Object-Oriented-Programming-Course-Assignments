#include "robot.h"
#include "humanic.h"
#include "romba.h"
#include "robocop.h"
#include "bulldozer.h"
#include "optimusPrime.h"
#include "world.h"


Optimusprime::Optimusprime(int sequence,int x, int y) : Humanic(100,100){ //to define constructor.
    string temp;
    temp = "OptimusPrime_"+ to_string(sequence); //to create name of robot with using creation number.
    setname(temp);
    this->x = x;
    this->y = y;
}

int Optimusprime::getType(){ //to define getType function.
    return 4;
}

int Optimusprime::getDamage(){ //to define getDamage function.
        int damage = Humanic::getDamage(); //to call getDamage function.
        if(rand() % 100 < 15 ){
            cout << "Strong attack !" << endl;
            damage *= 2;
        }
        return damage;
}
