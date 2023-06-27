#include <iostream>
#include <string>
using namespace std;
class DynamicStringArray {
private:
// A private member variable called dynamicArray
    string* dynamicArray;
//A private member variable called size that holds 
//the number of entries in the array.
    int size;
public:
//A default constructor that sets the dynamic array 
//to nullptr and sets size to 0.
    DynamicStringArray() : dynamicArray(nullptr), size(0) {
        //empty
    }
// A function that returns size.
    int getSize() const {
        return size;
    }
//A function named addEntry that takes a string as input
    void addEntry(const string& entry) {
        string* newArray = new string[size+1];
        for (int i = 0; i < size; i++) {
            newArray[i] = dynamicArray[i]; //create a new dynamic array 
            //one element larger than dynamicArray, copy all
            //elements from dynamicArray into the new array,
            // add the new string onto the
end of the new array,
        }
        newArray[size] = entry;
        size++;
        delete[] dynamicArray; //delete the old dynamicArray
        dynamicArray = newArray; //set dynamicArray to the new array.
    }

    bool deleteEntry(conststring& entry) {//A function named deleteEntry 
    //that takes a string as input.
        int index = -1; 
        for (int i = 0; i < size; i++) {
            if (dynamicArray[i] == entry) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return false;
        }
        string* newArray = new string[size-1];
        for (int i = 0, j = 0; i < size; i++) {
            if (i != index) {
                newArray[j++] = dynamicArray[i];
            }
        }
        size--;
        delete[] dynamicArray;
        dynamicArray = newArray;
        return true;
    }
//A function named getEntry that takes an integer as 
//input and returns the string at that index in dynamicArray. 
//It should return nullptr if the index is out of dynamicArray’s 
//bounds.
    string getEntry(int index) const {
        if (index < 0 || index >= size) {
            return nullptr;
        }
        return dynamicArray[index];
    }
//A copy constructor
    DynamicStringArray(const DynamicStringArray& other) : dynamicArray(nullptr), size(other.size) {
        if (size > 0) {
            dynamicArray = new string[size];
            for (int i = 0; i < size; i++) {
                dynamicArray[i] = other.dynamicArray[i];
            }
        }
    }
//Overload the assignment operator
    DynamicStringArray& operator=(const DynamicStringArray& other) {
        if (this != &other) {
            delete[] dynamicArray;
            size = other.size;
            if (size > 0) {
                dynamicArray = new string[size];
                for (int i = 0; i < size; i++) {
                    dynamicArray[i] = other.dynamicArray[i];
                }
            } else {
                dynamicArray = nullptr;
            }
        }
        return *this;
    }
//A destructor 
    ~DynamicStringArray() {
        delete[] dynamicArray;
    }
};

int main() {
    DynamicStringArray strArr;
    strArr.addEntry("Hello");
    strArr.addEntry("World");
    strArr.addEntry("!");
    cout << "Size of array: " << strArr.getSize() << endl;
    cout << "Array contents: ";
    for (int i = 0; i < strArr.getSize(); i++) {
        cout << strArr.getEntry(i) << " ";
    }
    cout << endl;
    strArr.deleteEntry("World");
    cout << "Size of array after deletion: " << strArr.getSize() << endl;
    cout << "Array contents after deletion: ";
    for (int i = 0; i < strArr.getSize(); i++) {
       cout << strArr.getEntry(i) << " ";
    }
    cout << endl;

    DynamicStringArray intArr;
    intArr.addEntry("1");
    intArr.addEntry("2");
    intArr.addEntry("3");
    cout <<
};