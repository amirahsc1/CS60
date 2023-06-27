#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"
using namespace std;
const int size = 20;
void print(const vector<Organism*>& grid) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Organism* organism = grid[i * size + j];
            if (organism) {
                if (typeid(*organism) == typeid(Ant))
                // “O” for an ant
                   cout << "O ";
                else if (typeid(*organism) == typeid(Doodlebug))
                // “X” for a doodlebug
                   cout << "X ";
            } 
            else {
               cout << "* ";
            }
        }
       cout << endl;
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    vector<Organism*> grid(size * size, nullptr);

    // Initialize the world with 5 doodlebugs and 100 ants.
    for (int i = 0; i < 100; i++) {
        int x = rand() % size;
        int y = rand() % size;
        if (!grid[x * size + y]) {
            grid[x * size + y] = new Ant(x, y);
        } else {
            i--;
        }
    }

    // Initialize the world with 5 doodlebugs and 100 ants.
    for (int i = 0; i < 5; i++) {
        int x = rand() % size;
        int y = rand() % size;
        if (!grid[x * size + y]) {
            grid[x * size + y] = new Doodlebug(x, y);
        } else {
            i--;
        }
    }

    // Simulation starts
    for (int iStep = 1; ; iStep++) {
       cout << "Number of Steps: " << iStep <<endl;
        print(grid);

        // Start moving
        for (Organism* organism : grid) {
            if (organism && typeid(*organism) == typeid(Doodlebug)) {
                organism->move(grid);
            }
        }

        for (Organism* organism : grid) {
            if (organism && typeid(*organism) == typeid(Ant)) {
                organism->move(grid);
            }
        }
       cout << "Press the Enter button to continue the stimulation";
       cin.ignore();
    }

    for (Organism* organism : grid) {
        delete organism;
    }

    return 0;
}


