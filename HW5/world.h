#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>


using namespace std;

const int WORLDSIZE = 10; //to define constant value.

class Robot;
class OptimusPrime;
class Humanic;
class Robocop;  //forward declaration.
class Romba;
class Bulldozer;


class World
{
    friend class Robot;
    friend class Humanic;
    friend class OptimusPrime; //to define friend classes.
    friend class Robocop;
    friend class Romba;
    friend class Bulldozer;
    
    private:
        Robot* grid[WORLDSIZE][WORLDSIZE]; //to define grid.
    public:
        World(); //to define default constructor.
        ~World(); //to define destructor.
        Robot* getblock(int x, int y); //to define getblock function.
        void setblock(int x, int y, Robot* org); //to define setblock function.
        void display(); //to define display function.
};

#endif

