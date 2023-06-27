/* 
Write a program that uses the class SalariedEmployee given in Display 14.4.
Your program is to define a derived class called Administrator, which is to be
derived from the class SalariedEmployee. You are allowed to change private in
the base class to protected. You are to supply the following additional data and
function members:
■ A member variable of type string that contains the administrator’s title, (such
as Director or Vice President).
■ A member variable of type string that contains the company area of responsibility (such as Production, Accounting, or Personnel).
■ A member variable of type string that contains the name of this administrator’s immediate supervisor.
■ A protected member variable of type double that holds the administrator’s
annual salary. It is possible for you to use the existing salary member if you
changed private in the base class to protected.
■ A member function called setSupervisor, which changes the supervisor name.
■ A member function for reading in an administrator’s data from the keyboard.
■ A member function called print, which outputs the object’s data to the screen.
■ Finally, an overloading of the member function printCheck( ) with appropriate
notations on the check. 
*/
#include <string>
#include <iostream>
#include "administrator.h"

using SavitchEmployees::Administrator;
int main()
{
Administrator myObj("Amirah Chandler", "713-443-6862", 1000000);
myObj.readData();
myObj.print();
myObj.printCheck();
return 0;
}
