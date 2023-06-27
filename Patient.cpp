//Patient.cpp
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
#include "Patient.h"

Patient::Patient(): Person(), doc(Doctor()){
    //empty
}
Patient::Patient(string pname, Doctor doc) : Person(pname), doc(doc){
	//empty
}
string Patient::getPatient(){
	return getName();
}
string Patient::getDoctor(){ //MIght be a problem
	return doc.getDoctor();
}
void Patient::setDoctor(Doctor doc) { 
    this->doc = doc; 
    }

Patient::Patient(const Patient& patobj) :Person(patobj){
	doc = patobj.doc;
}

Patient& Patient::operator=(const Patient& rtside){ //Might be a problem
	Person::operator=(rtside);
	doc = rtside.doc;
	return *this;
}