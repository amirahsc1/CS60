// 2. Problem 4 on page 917
// Write a program that prompts for and fetches data and builds 
// a vector of student records, then sorts the vector by name, 
// calculates the maximum and minimum grades, and the class
// average, then prints this summarizing data along with a class 
//roll with grades. 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct StudentInfo
{
    string name;
    int grade;
};

bool compareByName(const StudentInfo& student1, const StudentInfo& student2)
{
    return student1.name < student2.name;
}

int main()
{
    vector<StudentInfo> studentRecords;
    int myMax = 0;
    int myMin = 100;
    int finalGrade = 0;
    int students = 0;
    string stopInput = "stop";

    while (true)
    {
        StudentInfo student;
        cout << "Enter the name of student " << students + 1 << " (or 'stop' when done): ";
        cin >> student.name;

        if (student.name == stopInput)
            break;

        cout << "Enter the grade of student " << students + 1 << ": ";
        cin >> student.grade;

        studentRecords.push_back(student);

        myMax = max(myMax, student.grade);
        myMin = min(myMin, student.grade);
        finalGrade += student.grade;

        students++;
    }

    double average = static_cast<double>(finalGrade) / students;

    sort(studentRecords.begin(), studentRecords.end(), compareByName);
    cout << endl;
    cout << "Class Roll: " << endl;

    for (int i = 0; i < students; i++)
    {
        cout << studentRecords[i].name << " - Grade: " << studentRecords[i].grade << endl;
    }
    cout << endl;
    cout << endl;
    cout << "Maximum Grade: " << myMax  << endl;;
    cout << "Minimum Grade: " << myMin  << endl;;
    cout << "Average Grade: " << average << endl;;

    return 0;
}

