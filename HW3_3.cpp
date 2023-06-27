// Create a class named Student that has three member variables:
//  name – A string that stores the name of the student
//  numClasses – An integer that tracks how many courses the student is currently enrolled in
//  classList – A dynamic array of strings used to store the names of the
// classes that the student is enrolled in
// Write appropriate constructor(s), mutator, and accessor functions for the class
// along with the following:
//  • A function that inputs all values from the user, including the list of class names.
// This function will have to support input for an arbitrary number of classes.
//  • A function that outputs the name and list of all courses.
//  • A function that resets the number of classes to 0 and the classList to an
// empty list.
//  • An overloaded assignment operator that correctly makes a new copy of the list
// of courses.
//  • A destructor that releases all memory that has been allocated.
//  Write a main function that tests all of your functions.
#include <iostream>
using namespace std;
class Student
{
string name;
int numClasses;
string *classList;
public:
    Student(){
        name = "";
        numClasses = 0;
        classList = NULL;
    }
    void setName(string nm) { name = nm; }
    void setNumOfClasses(int num) { numClasses = num; }
    string getName() { return name; }
    int getNumClasses() { return numClasses; }
    string getClassName(int i) { return classList[i]; }
void InputData(){
    cout<<"Enter student name: ";
    cin>>name;
    cout<<"Enter number of classes: ";
    cin>>numClasses;
    classList = new string[numClasses];
    for(int i = 0; i < numClasses; i++){
        cout<<"Enter the name of every class" << endl;
        cin>>classList[i];
    }
}
Student& operator = (Student other){
    name = other.getName();
    numClasses = other.getNumClasses();
    classList = new string[numClasses];
    for(int i = 0; i < numClasses; i++)
    classList[i] = other.getClassName(i);
    return *this;
    }
void OutputData(){
    cout<<"Student Name: "<< name <<endl;
    cout<<"The number of classes the student is taking: "<< numClasses<<endl;
    for(int i = 0; i < numClasses; i++)
        cout <<"The student is taking: " << classList[i]<<endl;
    }
void ResetClasses(){
    delete[] classList;
    numClasses = 0;
    }
};

int main()
{
Student Student1;
Student studentCopy;
Student1.InputData(); 
cout << "Student 1's data: "<<endl;
Student1.OutputData();

studentCopy = Student1;
cout << "A copy of the students data: "<<endl;
studentCopy.OutputData(); 

Student1.ResetClasses();
cout << "Now we reset" << endl;
Student1.OutputData(); 
}