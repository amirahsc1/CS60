#include <fstream>
#include <vector>
#include "StudentInfo.h"
#include <string>
using namespace std;
vector <StudentInfo> studentFile(const string& studentlist1) {
    vector <StudentInfo> students;
    ifstream inputFile("studentlist1.txt");
    if (inputFile.is_open()) {
        string first_name, last_name, level;
        double gpa;
        while (inputFile >> first_name >> last_name >> level >> gpa) {
            StudentInfo student(first_name, last_name, level, gpa);
            students.push_back(student);
          }
        inputFile.close();
    }

    return students;
}
void output(const vector<StudentInfo>& students, const string& studentgpa) {
    ofstream outputFile("studentgpa.txt");
    if (outputFile.is_open()) {
        double totalGpa = 0.0;
        int count = 0;
        for (const StudentInfo& student : students) {
            totalGpa += student.getGpa();
            count++;
        }
        double averageGpa = totalGpa / count;
        // Sending average gpa to output file
        outputFile << "Average Student GPA: " <<  averageGpa << endl;
        // Sending students with GPA's above average
        outputFile << "Students with GPAs that are above average: " << endl;
        for (const StudentInfo& student:students) {
            if (student.getGpa() > averageGpa) {
                outputFile << student.getFirstName() << " " << student.getLastName() << endl;
            }
        }
        outputFile.close();
    }
}
int main(){
 vector<StudentInfo> students = studentFile("students.txt");
 cout << "Student List: " << endl;
     for (const StudentInfo& student:students) {
        cout << student.getFirstName() << " " << student.getLastName() <<" " << student.getClassLevel() << endl;
    }
    output(students, "studentgpa.txt");
  return 0;
}
