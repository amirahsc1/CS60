#ifndef ORGANISM_H
#define ORGANISM_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
class Organism {
public:
    Organism(int x, int y);
    //a virtual function named move that is defined in the 
    //classes of Ant and Doodlebug.
    virtual void move(vector<Organism*>& grid) = 0;
protected:
    int x_pos;
    int y_pos;
};
#endif