//Person.h
#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;
class Person{
public:
 Person();
 Person(string theName);
 Person(const Person& Obj1);
 string getName() const;
 void setName(string newName);
 Person& operator=(const Person& rtSide);
friend istream& operator >> (istream& inStream,Person& personObject);
friend ostream& operator << (ostream& outStream,const Person& personObject);
private:
 string name;
};
#endif