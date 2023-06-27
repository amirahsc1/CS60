#ifndef VEHICLE_H
#define VEHICLE_H
#include "Person.h"
class Vehicle{ //Base Class
public:
//Constructors
    Vehicle();
    Vehicle(const Vehicle& theObject);
// manufacturer’s name (type string),number of 
// cylinders in the engine (type int), and owner(type person)
    Vehicle(string m, int cyl, Person p);
    string get_m() const;
    void set_m(string m);
    int get_c() const;
    void set_c(int cyl);
    Person getOwner() const;
    void setOwner (Person p);
    void output();
    Vehicle& operator=(const Vehicle& rtSide);
private:
    string manufacturer;
    int num_c;
    Person owner;
};
#endif