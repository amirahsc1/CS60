#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <string>
#include "salariedemployee.h"
using namespace std;
// define a derived class called Administrator, which is to be
// derived from the class SalariedEmployee. 
namespace SavitchEmployees
{
class Administrator : public SalariedEmployee
{
public:
Administrator();
Administrator(const string& theName, const string& theSsn, double theAnnualSalary);
void setSupervisor(const string& newSupervisorName);
void readData();
void print();
void printCheck();
protected: //  allowed to change private in the base class to protected.
string adminTitle;
string areaOfResponsibility;
string supervisorName;
};
}
#endif