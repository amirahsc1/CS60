//truck.cpp
#include <string>
#include <iostream>
#include<cstdlib>
#include "Truck.h"
using namespace std;
Truck::Truck() : LC(0.0),TC(0), Vehicle() {
//empty
}

Truck::Truck(string m, int cyl, Person p, double load, int tow) : LC(load), TC(tow), Vehicle(m, cyl, p) {
//empty
}

Truck::Truck(const Truck& theObject) : LC(theObject.LC), TC(theObject.TC), Vehicle(theObject) {
//empty
}

double Truck::get_LC() const {
return LC;
}

int Truck::get_TC() const {
return TC;
}

void Truck::set_LC(double new_load) {
    LC = new_load;
}

void Truck::set_TC(int new_tc) {
    TC = new_tc;
}

void Truck::output() {
cout << "Load Capacity: " << get_LC() << endl;
cout << "Towing Capacity: " << get_TC() << endl;
Vehicle::output();
}

Truck& Truck::operator=(const Truck& rtSide) {
    LC = rtSide.LC;
    TC = rtSide.TC;
    return *this;

}