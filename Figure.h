#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
class Figure {
public:
//Each class has stubs for member functions erase and draw. 
    virtual void erase();
    virtual void draw();
    void center();
};
#endif