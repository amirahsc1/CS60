//Patient.h
#ifndef PATIENT_H
#define PATIENT_H
#include<iostream>
#include<string>
#include<cstdlib>
#include "Person.h"
#include "Doctor.h"

class Patient :public Person {
public:
	Patient();
	Patient(string pname, Doctor doc);
	Patient(const Patient& patobj);
	string getPatient();
	string getDoctor(); //Might be a problem
	void setDoctor(Doctor doc);
	Patient& operator=(const Patient& rtside);
private:
	Doctor doc;
};
#endif