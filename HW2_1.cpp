#include <iostream>
#include <string>
#include <cmath>
using namespace std;
/*
1. Write a grading program for a class with the following grading policies:
 a. There are two quizzes, each graded on the basis of 10 points.
 b. There is one midterm exam and one final exam, each graded on the basis of 100 points.
 c. The final exam counts for 50% of the grade, the midterm counts for 25%, and the two quizzes together count for a total of 25%. (Do not forget to normalize the quiz scores. They should be converted to a percentage before they are averaged in.)
*/

struct finalGrade
{
  int quiz1= 0;
  int quiz2 = 0;
  double midterm = 0.0;
  double finalExam = 0.0;
  double average = 0.0;
  char final_grade = 'A';
  double quizScore = 0;
};

void inputGrade (finalGrade& grade);
void setGrade(finalGrade& grade);

int main(){
finalGrade student;
inputGrade(student);
setGrade(student);

cout <<"The students first quiz score: " << student.quiz1 << endl;
cout <<"The students second quiz score: " << student.quiz2 << endl;
cout <<"The students final exam score: " << student.finalExam << endl;
cout <<"The students midterm score: " << student.midterm << endl;
cout << "The students final Grade is: " << student.average << ". " << "The students letter grade is: " << student.final_grade << endl;

  return 0;
}

void inputGrade (finalGrade& grade){
  cout << "Enter the score of the first quiz: ";
  cin >> grade.quiz1;
  cout << "Enter the score of the second quiz: ";
  cin >> grade.quiz2;
  cout << "Enter the score of the midterm: ";
  cin >> grade.midterm;
  cout << "Enter the score of the final exam: ";
  cin >> grade.finalExam;

}
void setGrade(finalGrade& grade){
grade.quizScore = grade.quiz2 + grade.quiz1;
grade.quizScore = (grade.quizScore/20) * 100;
grade.average = ((.25 * grade.quizScore ) + (.25 * grade.midterm) + (.50 * grade.finalExam)) ;
if(grade.average < 60){
grade.final_grade = 'F';}
if((grade.average > 60)&&(grade.average < 70)){
grade.final_grade = 'D';}
if((grade.average > 70)&&(grade.average < 80)){
grade.final_grade = 'C';}
if((grade.average > 80)&&(grade.average < 90)){
grade.final_grade = 'B';}
if(grade.average > 90){
grade.final_grade = 'A';}

}
