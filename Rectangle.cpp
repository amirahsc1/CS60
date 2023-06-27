#include <iostream>
#include "Figure.h"
#include "Rectangle.h"
using namespace std;
void Rectangle::erase() {
    cout << "Calling erase() in Rectangle class." << endl;
}
void Rectangle::draw() {
    cout << "Calling draw() in Rectangle class." << endl;
}