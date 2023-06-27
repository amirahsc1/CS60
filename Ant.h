#ifndef ANT_H
#define ANT_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Organism.h"
using namespace std;
class Ant: public Organism {
public:
    Ant(int x, int y);
    void move(vector<Organism*>& grid); 
    void breed(vector<Organism*>& grid);
private:
    int survivalTime;
};
#endif