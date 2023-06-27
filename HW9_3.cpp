// 3. Problem 5 on page 917 - part a only
//write a function that separates the students
// in the vector of StudentInfo records into two vectors, 
// one containing records of passing students and one containing 
// records of failing students. (Use a grade of 60 or better for passing.)
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

void separateStudents(vector<StudentInfo>& studentRecords, vector<StudentInfo>& passingStudents, vector<StudentInfo>& failingStudents)
{
    for (auto it = studentRecords.begin(); it != studentRecords.end();)
    {
        if (it->grade >= 60)
        {
            passingStudents.push_back(*it);
            it = studentRecords.erase(it);
        }
        else
        {
            failingStudents.push_back(*it);
            it++;
        }
    }
}

int main(){
    vector<StudentInfo> studentRecords;
    vector<StudentInfo> passingStudents;
    vector<StudentInfo> failingStudents;
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++)
    {
        StudentInfo student;
        cout << "Enter the name of student " << i + 1 << ": ";
        cin >> student.name;
        cout << "Enter the grade of student " << i + 1 << ": ";
        cin >> student.grade;

        studentRecords.push_back(student);
    }

    separateStudents(studentRecords, passingStudents, failingStudents);
    cout <<endl;
    cout << "Passing Students: ";
    cout <<endl;
    for (const auto& student : passingStudents)
    {
        cout << student.name << " - Grade: " << student.grade << endl;
    }
    cout <<endl;
    cout << "Failing Students: ";
    cout <<endl;
    for (const auto& student : failingStudents)
    {
        cout << student.name << " - Grade: " << student.grade << endl;
    }

    return 0;
}
