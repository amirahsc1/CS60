/*4. Problem 6 on page 736 of textbook
Do Programming Project 10.6 for the wrapper class around a dynamic array of
strings that allowed for the deletion and addition of string entries. Except this time,
use a template-based class so the implementation is not limited to strings. Test the
class with dynamic arrays of integers in addition to strings.
*/
#include <iostream>
using namespace std;
template <class T>
class DynamicArray {
private:
    T* a;
    int size;
    int capacity;

public:
    DynamicArray(int capacity = 10) {
        this->capacity = capacity;
        size = 0;
        a = new T[capacity];
    }

    ~DynamicArray() {
        delete[] a;
    }

    void add(T item) {
        if (size == capacity) {
            capacity *= 2;
            T* temp = new T[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = a[i];
            }
            delete[] a;
            a = temp;
        }
        a[size++] = item;
    }

    void delete_val(T item) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (a[i] == item) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            for (int i = index; i < size - 1; i++) {
                a[i] = a[i + 1];
            }
            size--;
        }
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Test with dynamic array of strings
    DynamicArray<string> stringArray;
    //Testing Strings
    stringArray.add("How");
    stringArray.add("Are");
    stringArray.add("You");
    stringArray.add("Today");
    //Testing print function
    stringArray.print();
    //Testind delete function
    stringArray.delete_val("Today");
    stringArray.print();

    // Numbers Test
    DynamicArray<int> intArray;
    intArray.add(10);
    intArray.add(100);
    intArray.add(1000);
    intArray.add(10000);
    intArray.print();

    intArray.delete_val(100);
    intArray.print();

    return 0;
}
