/* 
Create a base class called Vehicle that has the manufacturer’s name (type string),
number of cylinders in the engine (type int), and owner (type Person given in the
code that follows). Then create a class called Truck that is derived from Vehicle
and has additional properties, the load capacity in tons (type double since it may
contain a fractional part) and towing capacity in pounds (type int). Be sure your
classes have a reasonable complement of constructors and accessor methods, an
overloaded assignment operator, and a copy constructor. Write a driver program
that tests all your methods.*/
#include <iostream>
#include <cstdlib>
#include <string>
#include "Truck.h"
#include "Vehicle.h"
#include "Person.h"
using namespace std;

int main(){
string ownerName;
string manufacturerName;
int numCyl;
double load;
int TC;
//Testing Member Functions
cout << "Enter the name of the owner: ";
cin >> ownerName;
cout << "Enter the number of cylinders: ";
cin >> numCyl;
cout << "Enter the name of the manufacturer: ";
cin >> manufacturerName;
cout << "Enter the load capacity: ";
cin >> load;
cout << "Enter the towing capacity: ";
cin >> TC;
Truck myTruck;
Person Owner;
Owner.setName(ownerName);
myTruck.setOwner(Owner);
myTruck.set_m(manufacturerName);
myTruck.set_c(numCyl);
myTruck.set_LC(load);
myTruck.set_TC(TC);
Person ownerB("Link");
Truck yourTruck("Mercedes", 12, ownerB, 5000, 9000);
//Copy Constructor
Truck hisTruck(myTruck); //This is an object Truck obj and its copying the
//inputs of myTruck
//Testing Print Function
cout << "Owner of His Truck: " << hisTruck.getOwner() << endl;
cout << "Manufacturer: " << hisTruck.get_m() << endl;
cout << "Number of Cylinders: " << hisTruck.get_c() << endl;
cout << "Load Capacity: " << hisTruck.get_LC() << endl;
cout << "Towing Capacity: " << hisTruck.get_TC() << endl;
cout << endl;
//Testing the assignment operators
myTruck = yourTruck;
cout << "My Truck:  " << endl;
myTruck.output();
cout << endl;
cout << "Your Truck:  " << endl;
yourTruck.output();
cout << endl;

return 0;
}

