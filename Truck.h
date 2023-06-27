//Truck.h
#ifndef TRUCK_H
#define TRUCK_H
#include<iostream>
#include<string>
#include<cstdlib>
#include "Vehicle.h"
class Truck: public Vehicle{ // create a class called Truck that is derived from Vehicle
public:
    Truck();
    Truck(string m, int cyl, Person p, double load, int tow);
    Truck(const Truck& theObject);
    double get_LC() const;
    int get_TC() const;
    void set_LC(double newLoad);
    void set_TC(int newTowing);
    void output();
    Truck& operator=(const Truck& rtSide);
private:
    double LC;
    int TC;
};
#endif