//Problem 3 on page 826
#include <iostream>
#include "Polynomial.h"
using namespace std;
int main() {
    //Testing Default
    Polynomial myObj1;
    //Testing Constructor with one arguement
    Polynomial myObj2(-8);
    myObj2.insertTerm(3, 5);
    myObj2.insertTerm(-7, 3);
    myObj2.insertTerm(2, 1);
    //Testing Costructor with two arguments
    Polynomial myObj3(-7, 4); 
    myObj3.insertTerm(5, 2);
    myObj3.insertTerm(9, 0);

    Polynomial myObj4(myObj2); // Copy constructor

    cout << "Polynomial 1: ";
    myObj1.print();
    cout << endl;
    cout << "Polynomial 2: ";
    myObj2.print();
    cout << endl;
    cout << "Polynomial 3: ";
    myObj3.print();
    cout << endl;
    cout << "Polynomial 4: ";
    myObj4.print();
    cout << endl;
    //Testing + operator
    Polynomial sum = myObj2 + myObj3; 
    cout << "Poly 2 + Poly 3 = ";
    sum.print();
    cout << endl;
    //Testing - Operator
    Polynomial diff = myObj2 - myObj3; 
    cout << "Poly 2 - Poly 3 = ";
    diff.print();
    cout << endl;
    //Testing * operator
    Polynomial product = myObj2 * myObj3;
    cout << "Poly 2 * Poly 3 = ";
    product.print();
    cout << endl;
    int x = 2;
    //Testing Evaluation Function
    int eval = myObj2.evaluate(x); 
    cout << "When x = " << x << " the value of polynomial 2 is: " << eval << endl;
    cout << endl;
    // User Input Poly
    myObj1.inputPolynomial(); 
    cout << "Polynomial 1: ";
    myObj1.print();

    return 0;
}
