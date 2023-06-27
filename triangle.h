#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include "Figure.h"
using namespace std;
//Each class has stubs for member functions erase and draw. 
class triangle : public Figure {
public:
    void erase();
    void draw();
};
#endif