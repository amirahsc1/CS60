#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "Figure.h"
class Rectangle : public Figure {
public:
//Each class has stubs for member functions erase and draw. 
    void erase();
    void draw();
};
#endif