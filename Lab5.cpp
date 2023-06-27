#include <cstdlib>
#include <iostream>
#include <string>
#include "dbiguint.h"
using namespace std;

int main (){
dbiguint MyObj();
dbiguint MyObj2("111");
dbiguint MyObj3("11");
dbiguint MyObj4("1111");
//Testing += Operator
MyObj2+=MyObj3;
// Testin << Operator
cout<< MyObj2 << endl;
cout<< MyObj4 << endl;
return 0;
}


