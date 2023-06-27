#ifndef DOODLEBUG_H
#define DOODLEBUG_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Organism.h"
using namespace std;
class Doodlebug : public Organism {
public:
    Doodlebug(int x, int y);
    void move(vector<Organism*>& grid);
    void breed(vector<Organism*>& grid);
private:
    int survivalTime;
    int starveTIme;
};
#endif