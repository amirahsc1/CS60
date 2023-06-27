// Problem 1 on page 693.
#include <iostream>
#include "Figure.h"
#include "Rectangle.h"
#include "triangle.h"
 using namespace std;
 int main(){
    triangle tri;
    tri.draw();
    tri.center();
    cout << endl;
    Rectangle rect;
    rect.draw();
    rect.center(); //Calls draw and center
    cout << endl;
    return 0;
 }