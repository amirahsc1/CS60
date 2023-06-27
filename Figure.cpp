#include <iostream>
#include "Figure.h"
using namespace std;

void Figure::erase() {
    cout << "Calling erase() in Figure class." << endl;
}

void Figure::draw() {
    cout << "Calling draw() in Figure class." << endl;
}
//The member function center calls erase and draw to erase and 
//redraw the figure at the center.
void Figure::center() {
// add an output message in the member function center that announces that 
// center is being called.
    cout << "Calling center() in Figure class." << endl;
    erase();
    draw();
}
