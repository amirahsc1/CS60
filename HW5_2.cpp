/*2. Problem 2 on page 736 of textbook
Write a template version of the recursive binary search function from Display 13.6.
Specify requirements on the template parameter type. Discuss the requirements on
the template parameter type.
*/
#include <iostream>
using namespace std;
template <class T>
int recursiveSearch(const T a[], int lowEnd, int highEnd, const T& key) {
    if (lowEnd > highEnd) {
        return -1;
    }
    int mid = (lowEnd + highEnd) / 2;
    if (a[mid] == key) {
        return mid;
    } else if (a[mid] < key) {
        return recursiveSearch(a, mid + 1, highEnd, key);
    } else {
        return recursiveSearch(a, lowEnd, mid - 1, key);
    }
}
int main() {
    int a[] = {1, 3, 5, 7, 9, 11};
    int size = sizeof(a) / sizeof(a[0]);
    int key = 7;
    int index = recursiveSearch(a, 0, size - 1, key);
    if (index != -1) {
        cout << "Found " << key << " at index " << index << endl;
    } else {
        cout << key << " not found in array" << endl;
    }
return 0;
}