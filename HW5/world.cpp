#include "robot.h"
#include "humanic.h"
#include "romba.h"
#include "robocop.h"
#include "bulldozer.h"
#include "optimusPrime.h"
#include "world.h"
#include <iostream>


World::World() //to define default constructor.
{
    int i,j;
    for(i = 0; i < WORLDSIZE; i++){
        for(j = 0; j < WORLDSIZE; j++){
            grid[i][j] = NULL; //to assign NULL all the cells of grid.
        }
    }
}

World::~World() //to define destructor.
{
    int i,j;
    for(i = 0; i < WORLDSIZE; i++){
        for(j = 0; j < WORLDSIZE; j++){
            if(grid[i][j] != NULL) delete grid[i][j];
        }
    }
}

Robot* World::getblock(int x, int y){ //to define getblock function.
    if(x >= 0 && (x < WORLDSIZE) && y >= 0 && (y<WORLDSIZE))
        return grid[x][y];  

    return NULL;
}

void World::setblock(int x, int y, Robot *robot1){ //to define setblock function.
    if ((x>=0) && (x<WORLDSIZE) && (y>=0) && (y<WORLDSIZE)){
    grid[x][y] = robot1;
    }
}
void World::display(){ //to define display function.
    int i,j;
    cout << endl << endl;

    for(j = 0; j<WORLDSIZE; j++){
        for(i = 0; i < WORLDSIZE; i++){
            if(grid[i][j] == NULL) cout << "."; //to print . if cell is NULL. 
            else if(grid[i][j]->getType() == ROMBA) cout << "A"; //to print A if type of robot ing grid is Romba.
            else if(grid[i][j]->getType() == BULLDOZER) cout << "B"; //to print B if type of robot ing grid is Bulldozer.
            else if(grid[i][j]->getType() == ROBOCOP) cout << "P";   //to print P if type of robot ing grid is Robocop.          
            else cout << "O";
        }
        cout << endl;
    }
}
