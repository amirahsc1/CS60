#ifndef STUDENTINFO_H
#define STUDENTINFO_H
#include <iostream>
#include <string>
using namespace std;
class StudentInfo {
public:
    StudentInfo();
    StudentInfo(string first, string last, string level, double gpa_);
    string getFirstName() const;
    string getLastName() const;
    string getClassLevel() const;
    double getGpa() const;
private:
    string firstName;
    string lastName;
    string classLevel;
    double gpa;
};
#endif