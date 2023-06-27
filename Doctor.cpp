//Doctor.cpp
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
#include "Doctor.h"

Doctor::Doctor()
:docName("N/A"), speciality("N/A"), docFee(0.0) {
    //empty
}
Doctor::Doctor(string docName, string speciality, double docFee)
:docName(docName), speciality(speciality), docFee(docFee)
{
//empty
}
string Doctor::getDoctor(){
    return docName;
}
double Doctor::getFee(){
    return docFee;
}
string Doctor::getSpeciality(){
    return speciality;
}
void Doctor::setSpeciality(string  speciality){
        this-> speciality = speciality;
    }
void Doctor::setFee(double docFee){
        this->docFee = docFee;
    }
void Doctor::setDoctor(string docName){
    this->docName = docName;
}
Doctor::Doctor(const Doctor& Obj){
	docName = Obj.docName;
	docFee = Obj.docFee;
    speciality = Obj.speciality;
}
Doctor& Doctor::operator=(const Doctor& rtside){
	docName = rtside.docName;
    speciality = rtside.speciality;
	docFee = rtside.docFee;
	return *this;
}


	