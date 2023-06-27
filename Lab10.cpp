#include <cstdlib>
#include <iostream>
#include <string>
#include "lbiguint.h"
using namespace std;

int main (){
lbiguint MyObj();
lbiguint MyObj2("2023");
lbiguint MyObj3("13");
lbiguint MyObj4("134567");
// Testin << Operator
cout<< MyObj2 << endl;
cout<< MyObj3 << endl;
cout<< MyObj4 << endl;
return 0;
}