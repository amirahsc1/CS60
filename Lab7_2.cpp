#include <iostream>
#include "n_point.h"
#include "n_point.cpp"
using namespace std;
int main() {
    int myArray[5] = {13, 20, 22, 15, 16 };
    Point<int, 5> myObj1(5, myArray);
    for (int i = 0; i < myObj1.getSize(); i++) {
        cout << myObj1.getItem(i) << " ";
    }
    cout << endl;
    string myArray2[4] = { "dog", "cat", "turtle", "bunny"};
    Point<string, 4> myObj2(4, myArray2);
    for (int i = 0; i < myObj2.getSize(); i++) {
        cout << myObj2.getItem(i) << " ";
    }
    cout << endl;
    int myArray3[5] = {27, 99, 10, 4, 17 };
    Point<int, 5> myObj3(5, myArray3);
    myObj3 = myObj1;
    for (int i = 0; i < myObj3.getSize(); i++) {
        cout << myObj3.getItem(i) << " ";
    }
    cout << endl;
    return 0;
}