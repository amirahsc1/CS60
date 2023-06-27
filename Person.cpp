//person.cpp
#include <string>
#include <iostream>
#include<cstdlib>
#include "Person.h"
using namespace std;

Person::Person() {
    //empty
}

Person::Person(string theName): name(theName) {
 //empty    

}

Person::Person(const Person& Obj1): name(Obj1.name) {
     //empty
}

string Person::getName() const {
    return name;
}

void Person::setName(string newName) {
    this->name = newName;
}

Person& Person::operator=(const Person& rtSide) {
    name = rtSide.name;
    return *this;
}
istream& operator>> (istream& inStream, Person& personObject){
    inStream >> personObject.name;
    return inStream;
}
ostream& operator<< (ostream& outStream,const Person& personObject){
    outStream << personObject.getName();
    return outStream;
}

