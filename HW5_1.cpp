#include <iostream>
using namespace std;
template <typename T>
int binarySearch(T a[], int lowEnd, int highEnd, T key) {
    while (lowEnd <= highEnd) {
        int mid = (lowEnd + highEnd) / 2;

        if (a[mid] == key) {
            return mid;
        }
        else if (a[mid] < key) {
            lowEnd = mid + 1;
        }
        else {
            highEnd = mid - 1;
        }
    }

    return -1;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int key = 5;

    int result = binarySearch<int>(a, 0, n - 1, key);

    if (result == -1) {
        std::cout << "Element not found\n";
    }
    else {
        std::cout << "Element found at index " << result << "\n";
    }

    return 0;
}
