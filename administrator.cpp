//administrator.cpp
// File adminstrator.cpp
#include <string>
#include <iostream>
#include "administrator.h"
#include "salariedemployee.h"
#include "employee.h"
using namespace std;
namespace SavitchEmployees{ 
//Default Constructor
Administrator::Administrator() :SalariedEmployee(){
//empty
}
//Constructor
Administrator::Administrator(const string& theName, const string& theSsn,double theAnnualSalary) 
:SalariedEmployee(theName, theSsn, theAnnualSalary){
//empty
// derived from the class SalariedEmployee. 
}
//A member function called setSupervisor, which changes the supervisor name.
void Administrator::setSupervisor(const string& newSupervisorName){
supervisorName = newSupervisorName;
}
//A member variable of type string that contains the administrator’s title, (such
// as Director or Vice President).
//A member function for reading in an administrator’s data from the keyboard.
void Administrator::readData(){
cout << "Enter the details of the administrator " << getName()//From employee.cpp header included in file
<< endl;
cout << " Enter the administrator's title: "; 
getline(cin, adminTitle); //Use getline() function to get the values
// for the private varibles from the class
cout << " Enter the company area of responsibility: ";
getline(cin, areaOfResponsibility);
cout << " Enter the name of this administrator's immediate supervisor: ";
getline(cin, supervisorName);
}

//A member function called print, which outputs the object’s data to the screen.
void Administrator::print()
{
cout << "\nDetails of the administrator..." << endl;
cout << "Administrator's name: " << getName() << endl;
cout << "Administrator's title: " << adminTitle << endl;

//contains the company area of responsibility (such as Production, Accounting, or Personnel).
cout << "Area of responsibility: " << areaOfResponsibility << endl; //Got using getline() function
cout << "Immediate supervisor's name: " << supervisorName << endl;
}
//overloading of the member function printCheck( ) with appropriate
//notations on the check. 
void Administrator::printCheck(){//From hourlyemployee.cpp its 
// header is included in the file
        setNetPay(salary);
        cout << "\n__________________________________________________\n";
        cout << "Pay to the order of " << getName( ) << endl;
        cout << "The sum of " << getNetPay( ) << " Dollars\n";
        cout << "_________________________________________________\n";
        cout << "Check Stub NOT NEGOTIABLE \n";
        cout << "Employee Number: " << getSsn( ) << endl;
        cout << "Salaried Employee. Regular Pay: "
             << salary << endl;
        cout << "_________________________________________________\n";
    }
} 
