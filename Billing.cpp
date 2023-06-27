//Billing.cpp
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
#include "Billing.h"

Billing::Billing(): patient(Patient()), doctor(Doctor()), totalBill(0.0) {}
Billing::Billing(Patient patient, Doctor doctor, double totalBill)
    : patient(patient), doctor(doctor), totalBill(totalBill) {}

string Billing::getPatient(){ 
    return patient.getPatient(); 
    }
string Billing::getDoctor(){ 
    return doctor.getDoctor(); 
    }
double Billing::get_totalBill(){ 
    return totalBill; 
    }

void Billing::setPatient(Patient patient) { 
    this->patient = patient; 
    }
void Billing::setDoctor(Doctor doctor) { 
    this->doctor = doctor; 
    }
void Billing::set_totalBill(double totalBill) { 
    this->totalBill = totalBill; 
    }
Billing::Billing(const Billing& objBill)
:patient(patient), doctor(doctor), totalBill(totalBill) {
	patient = objBill.patient;
    doctor = objBill.doctor;
	totalBill = objBill.totalBill;
}
Billing& Billing::operator=(const Billing& rtside){
	patient = rtside.patient;
    doctor = rtside.doctor;
	totalBill = rtside.totalBill;
	return *this;
}
