#ifndef ROBOT_H
#define ROBOT_H

#include "world.h"

const int ROMBA = 1;
const int BULLDOZER = 2; //to define constant values for robot types.
const int ROBOCOP = 3;
const int OPTIMUSPRIME = 4;

class Robot
{
    friend class World; //to define friend class world.

    public:
        Robot(); //to define default constructor.
        Robot(int Stregth , int Hitpoints); //to define constructor.
        Robot(World* world, int x, int y); //to define constructor.
        ~Robot(); //to define destructor.
        virtual int getDamage() = 0; //to define virtual getDamage function.
        virtual int getType() = 0; //to define virtual getType function.
        int getStrength();
        int getHitPoints();  //to define getter functions for protected values.
        void setStrength (int new_strength);
        void setHitPoints(int new_HitPoints); //to define setter functions for protected values.
        int getX(){return x;}
        int getY(){return y;}
        string getname();
        void setname(string name);        
        void move(World* w); //to define mmove function.
        int fight(Robot *robot); //to define fight function.
        void setX(int newx);
        void setY(int newy);
        bool getmove();
        void setmove(bool move);
    protected:
        string name;//to define protected values.
        int strength;
        int hitPoints;
        bool moved;
        World* world;
        int x,y;
};



#endif