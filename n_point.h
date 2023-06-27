#ifndef N_POINT_H
#define N_POINT_H
#include  <iostream>
using namespace std;
template<typename T, int size>
class Point {
private:
    static const int MAX_SIZE = 10;
    int dimension;
    T arr[MAX_SIZE]; //every attempt to
public:
    // Constructors
    Point();
    Point(int dim);
    Point(int dim, const T a[size]);
    // Getter for the ith item in the arr
    T getItem(int i) const;
    // Getter for the size
    int getSize() const;
    //Overload =
    void operator=(const Point<T, size>& other);
};

#endif // n_point.h