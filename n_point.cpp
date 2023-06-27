//n_point.cpp
#include <iostream>
#include "n_point.h"
using namespace std;
template<typename T, int size>
Point<T,size>::Point() {
    dimension = 0;
}

template<typename T, int size>
Point<T,size>::Point(int dim) {
    dimension = dim;
}

template<typename T, int size>
Point<T,size>::Point(int dim, const T a[size]) {
    dimension = dim;
    for (int i = 0; i < dimension; i++) {
        arr[i] = a[i];
    }
}

template<typename T, int size>
T Point<T,size>::getItem(int i) const {
    return arr[i];
}

template<typename T, int size>
int Point<T,size>::getSize() const {
    return dimension;
}

template<typename T, int size>
void Point<T, size>::operator=(const Point<T, size>& rhs) {
    dimension = rhs.dimension;
    for (int i = 0; i < dimension; i++) {
        arr[i] = rhs.arr[i];
    }
}

