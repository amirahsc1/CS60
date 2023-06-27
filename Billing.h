#ifndef BILLING_H
#define BILLING_H
#include<iostream>
#include<string>
#include<cstdlib>
#include "Patient.h"
#include "Doctor.h"
using namespace std;
class Billing {
private:
    Patient patient;
    Doctor doctor;
    double totalBill;
public:
    Billing();
    Billing(Patient patient, Doctor doctor, double totalBill);
    string getPatient();
    string getDoctor();
    double get_totalBill();
    void setPatient(Patient patient);
    void setDoctor(Doctor doctor);
    void set_totalBill(double totalBill);
    Billing(const Billing& objBill);
    Billing&operator=(const Billing& objBill);
};
#endif
