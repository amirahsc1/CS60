#include <iostream>
#include <string>
using namespace std;
// Write a program that converts from 24-hour notation to 12-hour notation. For example, 
// it should convert 14:25 to 2:25 P.M. The input is given as two integers. There should 
// be at least three functions: one for input, one to do the conversion, and one for 
// output. Record the A.M./P.M. information as a value of type char, 'A' for A.M. 
// and 'P' for P.M. Thus, the function for doing the conversions will have a call-by-reference 
// formal parameter of type char to record whether it is A.M. or P.M. (The function will have 
// other parameters as well.) Include a loop that lets the user repeat this computation for new 
// input values again and again until the user says he or she wants to end the program.


// My Functions
void input(int &, int &, char &); 
void conversion(int &, int &, char &);
void output(int &, int &, char &);

int main () {
  int hour, minute;
  char day;
  char stop;

while (stop != 'n')
	{
		input(hour,minute, day);
		conversion(hour, minute, day);
		output( hour, minute, day);

		cout << "Press 'n' to stop the program or 'y' to continue" << endl;
		cin >> stop;

    if (stop == 'y'){
      input(hour,minute, day);
      conversion(hour, minute, day);
      output( hour, minute, day);
      cout << "Press 'n' to stop the program or 'y' to continue" << endl;
      cin >> stop;
    }

  }


  return 0;
}
// Function Defintions
void input(int &hour, int &minute, char &day ) {

  cout << "What is the hour" << endl;
  cin >> hour;
  cout << "What is the the minute" << endl;
  cin >> minute;
}

void conversion(int &hour, int &minute, char &day ){
    if (hour > 12){
      hour = hour - 12;
      day = 'p';
    }
    else if (hour == 12){
      day ='p';

    }
    else {
      day = 'a';
    }

  }

void output(int &hour, int &minute, char &day){
  if (day =='p'){
    cout << "The time in 12-Hour notation is:"<<hour<<":"<<
    minute << " P.M" << endl;
  }
  else{
  cout << "The time in 12-Hour notation is:"<<hour<<":"<<
  minute << " A.M" << endl;
}
}