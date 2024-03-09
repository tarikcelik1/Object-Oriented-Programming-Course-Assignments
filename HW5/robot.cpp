#include "robot.h"
#include "humanic.h"
#include "romba.h"
#include "robocop.h"
#include "bulldozer.h"
#include "optimusPrime.h"
#include "world.h"


Robot::Robot(){ //to define default constructor.
    world = NULL;
    moved = false;
    strength = 0;
    hitPoints = 0;
    x = 0;
    y = 0;
}

Robot::Robot(int Strength, int Hitpoints){ //to define constructor.
    moved = false;
    strength = Strength;
    hitPoints = Hitpoints;
}

Robot::Robot(World* world ,int x, int y){ //to define constructor.
    this->world = world;
    moved = false;
    strength = 0;
    hitPoints = 0;
    this->x = x;
    this->y = y;
    world->setblock(x, y, this);
}

Robot::~Robot(){} //to define destructor.

int Robot::getDamage(){
        int damage = (rand() % strength) + 1;
        return damage;
}

int Robot::getStrength(){   //to implement getter functions.
    return strength;
} 
int Robot::getHitPoints(){
    return hitPoints;
}
void Robot::setStrength(int new_strength){
    this->strength = new_strength;
}
void Robot::setHitPoints(int new_HitPoints){
    this->hitPoints = new_HitPoints;
}
string Robot::getname(){
    return name;
}

void Robot::setname(string name){
    this->name = name;
}

void Robot::setmove(bool move){ //to define setter functions.
    this->moved = move;
}

void Robot::setX(int newx){
    this->x = newx;
}

void Robot::setY(int newy){
    this->y = newy;
}

bool Robot::getmove(){
    return moved;
}

int Robot::fight(Robot* other) //to define fight function.
{/*
* This function takes another robot and fights them.
*/
    while (other->getHitPoints() > 0 &&  this->getHitPoints() > 0) //to create a while loop for until one of the robot dies.
    {
        int damage = this->getDamage(); //to call getDamage function for get damage of robot. 
        other->setHitPoints(other->getHitPoints() - damage);
        cout << this->getname() << "(" << this->getHitPoints() << ") hits " << other->getname() << "(" << other->getHitPoints() + damage << ") with " << damage << endl;
        if (other->getHitPoints() <= 0)//to check robot dies or not.
        {
            cout << other->getname() << " is dead!" << endl<<endl; //to print death message.
            return 2;
        }
        else{
            damage = other->getDamage();//to call getDamage function for get damage of robot. 
            this->setHitPoints(hitPoints - damage);
            cout << other->getname() << "(" << other->getHitPoints() << ") hits " << this->getname() << "(" << this->getHitPoints() + damage << ") with " << damage << endl;
            if (this->getHitPoints() <= 0)
            {
                cout << this->getname() << " is dead!" << endl<<endl; //to print death message.
                return 1;
            }
        }
    }
    return 0;
}

void Robot::move(World* w){ //to define move function.
/*
* This function takes world and it moves robots and figth them.
*/
    int attackeroroffenser;
    int x = this->getX();
    int y = this->getY();
    int otherx,othery;
    for(int i=0;i<WORLDSIZE;i++){
        for(int j=0;j<WORLDSIZE;j++){
            if((i != x || j != y) && w->getblock(i,j) != NULL){ //to check given index robot is same or not.
               otherx = i;
               othery = j; 
            }
        }
    }
                attackeroroffenser = this->fight(w->getblock(otherx,othery));
                if(attackeroroffenser == 1){ //to check whodies.
                    w->setblock(x,y,NULL); //attacker dead and its grid assign as NULL.
                }
                else{
                    w->setblock(otherx,othery,NULL); //offenser is dead and its grid assign as NULL.
                    w->setblock(otherx,othery,this); //to assign offenserrs grid to attacker.
                    w->setblock(x,y,NULL);
                    w->getblock(otherx,othery)->setX(otherx);
                    w->getblock(otherx,othery)->setY(othery);
                }
}
