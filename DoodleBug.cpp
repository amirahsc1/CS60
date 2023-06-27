#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"
using namespace std;
const int size = 20;
Doodlebug::Doodlebug(int x, int y) : Organism(x, y), survivalTime(0), starveTIme(0) {
    //empty
}
// For every time step, the doodlebug will move to an adjacent cell containing an ant and eat the ant. If there are no ants in adjoining cells, the doodlebug
// moves according to the same rules as the ant. Note that a doodlebug cannot eat
// other doodlebugs.
void Doodlebug::move(vector<Organism*>& grid) {
    // look for an ant in an adjacent position
    if (x_pos > 0 && grid[(x_pos - 1) * size + y_pos] && typeid(*grid[(x_pos - 1) * size + y_pos]) == typeid(Ant)) {
        // Eat the ant
        delete grid[(x_pos - 1) * size + y_pos];
        grid[(x_pos - 1) * size + y_pos] = this;
        grid[x_pos * size + y_pos] = nullptr;
        x_pos--;
        survivalTime++;
        starveTIme = 0;
    } else if (x_pos < size - 1 && grid[(x_pos + 1) * size + y_pos] && typeid(*grid[(x_pos + 1) * size + y_pos]) == typeid(Ant)) {
        // Eat the ant
        delete grid[(x_pos + 1) * size + y_pos];
        grid[(x_pos + 1) * size + y_pos] = this;
        grid[x_pos * size + y_pos] = nullptr;
        x_pos++;
        survivalTime++;
        starveTIme = 0;
    } else if (y_pos > 0 && grid[x_pos * size + (y_pos - 1)] && typeid(*grid[x_pos * size + (y_pos - 1)]) == typeid(Ant)) {
        // Eat the ant
        delete grid[x_pos * size + (y_pos - 1)];
        grid[x_pos * size + (y_pos - 1)] = this;
        grid[x_pos * size + y_pos] = nullptr;
        y_pos--;
        survivalTime++;
        starveTIme = 0;
    } else if (y_pos < size - 1 && grid[x_pos * size + (y_pos + 1)] && typeid(*grid[x_pos * size + (y_pos + 1)]) == typeid(Ant)) {
        // Eat the ant
        delete grid[x_pos * size + (y_pos + 1)];
        grid[x_pos * size + (y_pos + 1)] = this;
        grid[x_pos * size + y_pos] = nullptr;
        y_pos++;
        survivalTime++;
        starveTIme = 0;
    } else {
        // If you can't find an ant choose a random position
        int pos = rand() % 4;
        int new_x = x_pos;
        int new_y = y_pos;

        if (pos == 0 && x_pos > 0)
            new_x--;
        if (pos == 1 && x_pos < size - 1)
            new_x++;
        if (pos == 2 && y_pos > 0)
            new_y--; 
        if (pos == 3 && y_pos < size - 1)
            new_y++; 
        if (new_x >= 0 && new_x < size && new_y >= 0 && new_y < size && !grid[new_x * size + new_y]) {
            grid[new_x * size + new_y] = this;
            grid[x_pos * size + y_pos] = nullptr;
            x_pos = new_x;
            y_pos = new_y;
            survivalTime++;
            starveTIme++;
            if (survivalTime % 8 == 0) {
                breed(grid);
            }

            // If a doodlebug has not eaten an ant within three time steps, 
            // at the end of the third time step it will starve and die. 
            // The doodlebug should then be removed from the grid of cells
            if (starveTIme == 3) {
                grid[x_pos * size + y_pos] = nullptr;
                delete this;
            }
        }
    }
}
// If a doodlebug survives for eight time steps, at the end of the time step it
// will spawn off a new doodlebug in the same manner as the ant
void Doodlebug::breed(vector<Organism*>& grid) {
    //Checks if the cell adjacent to the current pos
    //is empty in every direction
    vector<pair<int, int>> emptyCells;
    if (x_pos > 0 && !grid[(x_pos - 1) * size + y_pos])
        emptyCells.push_back(make_pair(x_pos - 1, y_pos)); 
    if (x_pos < size - 1 && !grid[(x_pos + 1) * size + y_pos])
        emptyCells.push_back(make_pair(x_pos + 1, y_pos)); 
    if (y_pos > 0 && !grid[x_pos * size + (y_pos - 1)])
        emptyCells.push_back(make_pair(x_pos, y_pos - 1)); 
    if (y_pos < size - 1 && !grid[x_pos * size + (y_pos + 1)])
        emptyCells.push_back(make_pair(x_pos, y_pos + 1)); 
    // of the cells we determined to be empty we randomly pick
    // one and then add an ant to it
    if (!emptyCells.empty()) {
        int randomIndex = rand() % emptyCells.size();
        int new_x = emptyCells[randomIndex].first;
        int new_y = emptyCells[randomIndex].second;
        grid[new_x * size + new_y] = new Doodlebug(new_x, new_y);
    }
}



