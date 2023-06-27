/*
3. Problem 5 on page 736 of textbook
Write a template-based class that implements a set of items. The class should allow
the user to
a. Add a new item to the set.
b. Get the number of items in the set.
c. Get a pointer to a dynamically created array containing each item in the set.
The caller of this function is responsible for deallocating the memory.
 Test your class by creating sets of different data types (e.g., integers, strings).
*/
#include <iostream>
using namespace std;

template<class T>
class set_of_items {
private:
    T *items;
    int size;
    int capacity;

public:
    set_of_items(int capacity = 10) {
        this->capacity = capacity;
        size = 0;
        items = new T[capacity];
    }

    ~set_of_items() {
        delete [] items;
    }

    void addItems(T item) {
        if (size == capacity) {
            // double the capacity
            capacity *= 2;
            T *temp = new T[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = items[i];
            }
            delete [] items;
            items = temp;
        }
        items[size++] = item;
    }

    int getSize() const {
        return size;
    }

    T* toArray() const {
        T *arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = items[i];
        }
        return arr;
    }
};

int main() {

    set_of_items<int> intSet;
    intSet.addItems(54);
    intSet.addItems(23);
    intSet.addItems(13);
    int *intArr = intSet.toArray();
    for (int i = 0; i < intSet.getSize(); i++) {
        cout << intArr[i] << " ";
    }
    cout << endl;
    delete [] intArr;

  
    set_of_items<string> stringSet;
    stringSet.addItems("live");
    stringSet.addItems("laugh");
    stringSet.addItems("love");
    string *stringArr = stringSet.toArray();
    for (int i = 0; i < stringSet.getSize(); i++) {
        cout << stringArr[i] << " ";
    }
    cout << endl;
    delete [] stringArr;

    return 0;
}

