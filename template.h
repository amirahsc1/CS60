#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <array>
#include <cstddef>
using namespace std;
template<typename T, int size>
class Point {
private:
    static const int MAX_SIZE = 10;
    int dimension;
    T arr[size];
public:
    // Constructors
    Point() {
        dimension = 0;
    }

    Point(int dim) {
        if (dim <= MAX_SIZE) {
            dimension = dim;
        } else {
            cout << "Invalid dimension" << endl ;
        }
    }

    Point(int dim, const T a[size]) {
        if (dim <= size) {
            dimension = dim;
            for (int i = 0; i < dimension; i++) {
                arr[i] = a[i];
            }
        } else {
            cout << "Invalid dimension" << endl;
        }
    }

    // Getter for the ith item in the arr
    T getItem(int i) const {
        if (i < 0 || i >= dimension) {
            cout << "Invalid index" << endl;
        }
        return arr[i];
    }

    // Getter for the size
    int getSize() const {
        return dimension;
    }
};

#endif // n_point.h