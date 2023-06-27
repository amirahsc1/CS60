#include <iostream>
#include <string>
#include "StudentInfo.h"
using namespace std;
StudentInfo::StudentInfo() {
    firstName = "";
    lastName = "";
    classLevel = "";
    gpa = 0.0;
}
StudentInfo::StudentInfo(string first_name, string last_name, string level, double gpa_) {
    firstName = first_name;
    lastName = last_name;
    classLevel = level;
    gpa = gpa_;
}

string StudentInfo::getFirstName() const {
    return firstName;
}

string StudentInfo::getLastName() const {
    return lastName;
}

string StudentInfo::getClassLevel() const {
    return classLevel;
}

double StudentInfo::getGpa() const {
    return gpa;
}
