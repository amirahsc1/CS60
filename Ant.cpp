#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Organism.h"
#include "Ant.h"
using namespace std;
const int size = 20;
Ant::Ant(int x, int y) : Organism(x, y), survivalTime(0) {
    //empty
}
// For every time step, the ants randomly try to move up, down, left, or
// right. If the neighboring cell in the selected direction is occupied or would
// move the ant off the grid, then the ant stays in the current cell
void Ant::move(vector<Organism*>& grid){
    // Randomly choose a pos
    int pos = rand() % 4;
    int new_x = x_pos;
    int new_y = y_pos;
    if (pos == 0) {
        new_x--; 
    } else if (pos == 1) {
        new_x++;
    } else if (pos == 2) {
        new_y--;
    } else {
        new_y++; 
    }

    if (new_x >= 0 && new_x < size && new_y >= 0 && new_y < size && !grid[new_x * size + new_y]) {
        grid[new_x * size + new_y] = this;
        grid[x_pos * size + y_pos] = nullptr;
        x_pos = new_x;
        y_pos = new_y;
        survivalTime++;
        if (survivalTime % 3 == 0) {
            breed(grid);
        }
    }
}
// If an ant survives for three time steps, at the end of the time step (i.e.,
// after moving) the ant will breed. This is simulated by creating a new ant in an
// adjacent (up, down, left, or right) cell that is empty. If there is no empty cell
// available, no breeding occurs. Once an offspring is produced, an ant cannot
// produce an offspring again until it has survived three more time steps
void Ant::breed(vector<Organism*>& grid) {
    vector<pair <int, int> > emptyCells;
    //Checks if the cell adjacent to the current pos
    //is empty in every direction
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
        grid[new_x * size + new_y] = new Ant(new_x, new_y);
    }
}

