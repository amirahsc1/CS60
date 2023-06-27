//Doctor.h
#ifndef DOCTOR_H
#define DOCTOR_H
#include <iostream>
#include <string>
#include <cstdlib>

class Doctor {
public:
	Doctor();
	Doctor(string name, string speciality, double docFee);
	Doctor(const Doctor& Obj);
	string getDoctor();
	string getSpeciality();
	double getFee();
	void setSpeciality(string specialty);
	void setFee(double docFee) ;
	void setDoctor(string docName);
	Doctor& operator=(const Doctor& rtside);
private:
	string speciality;
	double docFee;
	string docName;
};
#endif