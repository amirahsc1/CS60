//vehicle.cpp
#include <string>
#include <iostream>
#include<cstdlib>
#include "Vehicle.h"
using namespace std;
Vehicle::Vehicle(){
//empty
}
Vehicle::Vehicle (string m, int cyl, Person p): manufacturer(m),
num_c(cyl), owner(p){
}


Vehicle::Vehicle(const Vehicle& theObject){
manufacturer = theObject.manufacturer;
num_c = theObject.num_c;
owner = theObject.owner;
}

string Vehicle::get_m() const{
return manufacturer;
}

void Vehicle::set_m (string m){
manufacturer = m;
}

int Vehicle::get_c() const{
return num_c;
}

void Vehicle::set_c(int n){
num_c = n;
}

Person Vehicle::getOwner() const{
return owner;
}

void Vehicle::setOwner(Person p){
owner = p;
}

Vehicle& Vehicle::operator=(const Vehicle& rtSide){
manufacturer = rtSide.manufacturer;
num_c = rtSide.num_c;
owner = rtSide.owner;
return *this;
}
void Vehicle::output(){
cout << "Owner: " << owner << endl;
cout << "Manufacturer: " << manufacturer << endl;
cout << "Number of Cylinders: " << num_c << endl;
}