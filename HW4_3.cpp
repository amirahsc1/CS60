/* Give the definition of two classes, Patient and Billing, whose objects are records for a clinic. Patient will be derived from the class Person given in Programming Project 14.4. A Patient record has the patient’s name (inherited from
the class Person) and primary physician, of type Doctor defined in Programming
Project 14.3. A Billing object will contain a Patient object and a Doctor object,
and an amount due of type double. Be sure your classes have a reasonable complement of constructors and accessor methods, an overloaded assignment operator,
and a copy constructor. First write a driver program to test all your methods, then
write a test program that creates at least two patients, at least two doctors, at least
two Billing records, then prints out the total income from the Billing records 

Give the definition of a class named Doctor whose objects are records for a clinic’s
doctors. This class will be a derived class of the class SalariedEmployee given
in Display 14.4. A Doctor record has the doctor’s specialty (such as Pediatrician,
Obstetrician, General Practitioner, etc., so use type string) and office visit fee
(use type double). Be sure your class has a reasonable complement of constructors
and accessor methods, an overloaded assignment operator, and a copy constructor.
Write a driver program to test all your methods.
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include "billing.h"
#include "Patient.h"
#include "Doctor.h"

using namespace std;
int main(){
//First write a driver program to test all your methods
	//Driver for Doctor.cpp
	Doctor dr1("Johnson", "Pediatric", 75.0);
	Doctor dr2("Jordan", "Therapist", 90.0);
	//Driver for Patient.cpp
	Patient patient1("Sarah", dr1);
	Patient patient2("Marcus", dr2);
	//Drive for Billing.cpp
	Billing billing1(patient1, dr1, 5000.0);
	Billing billing2(patient2, dr2, 1200.0);
	//Test Program
	cout << "Doctor's Name: " << dr1.getDoctor() <<endl;
	cout << "Their Speciality: " << dr1.getSpeciality() << endl;
	cout << "Their Current Fee: "<< dr1.getFee() << endl;
	cout << endl << endl;
	cout << "Doctor's Name: " << dr2.getDoctor() <<endl;
	cout << "Their Speciality: " << dr2.getSpeciality() << endl;
	cout << "Their Current Fee: " << dr2.getFee() << endl;
	cout << endl << endl;
	cout << "Patients Name: " << patient1.getPatient() << endl;
	cout << "Patients Doctor: " << patient1.getDoctor() << endl;
	cout << "Patients Name: " << patient2.getPatient() << endl;
	cout << "Patients Doctor: " << patient2.getDoctor() << endl;
	double totalIncome = billing1.get_totalBill() + billing2.get_totalBill();

    cout << "Total income from Billing records: $" << totalIncome << endl;

	return 0;
}