#include <iostream>
#include <string>
#include "robot.h"
#include "humanic.h"
#include "romba.h"
#include "robocop.h"
#include "bulldozer.h"
#include "optimusPrime.h"
#include "time.h"

using namespace std;

const int NUM_OF_PER_ROBOT = 5; //to define constant integer for number of per robot.


int main(){
    World w; //to create a world object.
    srand(time(NULL)); 
    int numofrobots = 0;
    for(int i = 0; i < NUM_OF_PER_ROBOT; i++){ //to create a loop for create each robot.
        int x,y;
        
        do{
            x = rand() % 10;
            y = rand() % 10;
        }while(w.getblock(x,y) != NULL); //to chechk randomly created indexes are NULL or not.
        Romba* A = new Romba(i,x,y); //to create Romba object.
        w.setblock(x,y,A); //to set grid cell to created object.
        numofrobots++; //to increase numofrobots by 1.

        do{
            x = rand() % 10;
            y = rand() % 10;
        }while(w.getblock(x,y) != NULL);//to chechk randomly created indexes are NULL or not.
        Bulldozer* B = new Bulldozer(i,x,y); //to create Bulldozer object.
        w.setblock(x,y,B); //to set grid cell to created object.
        numofrobots++;//to increase numofrobots by 1.

        do{
            x = rand() % 10;
            y = rand() % 10;
        }while(w.getblock(x,y) != NULL);//to chechk randomly created indexes are NULL or not.
        Robocop* P = new Robocop(i,x,y); //to create Robocop object.
        w.setblock(x,y,P);//to set grid cell to created object.
        numofrobots++;//to increase numofrobots by 1.

        do{
            x = rand() % 10;
            y = rand() % 10;
        }while(w.getblock(x,y) != NULL);//to chechk randomly created indexes are NULL or not.
        Optimusprime* O = new Optimusprime(i,x,y); //to create Optimusprime object.
        w.setblock(x,y,O);//to set grid cell to created object.
        numofrobots++;//to increase numofrobots by 1.
    }
    
    w.display(); //to print initial verison of grid.
    cout<<endl;
    while (numofrobots > 1) //to create a loop for fight of robots until one of them stays.
    {
        for(int i = 0; i < WORLDSIZE; i++){
                for(int j = 0; j < WORLDSIZE; j++){
                    if(w.getblock(i,j) != NULL){ //to find a robot for move.
                        w.getblock(i,j)->move(&w); //to move founded robots.
                        numofrobots--; //to decrease numofrobots by 1.
                        i=WORLDSIZE;
                        j=WORLDSIZE;
                        break;
                    }
                }
            }          
        }
    w.display(); //to define final version of grid.
    

    return 0;
}