#include <iostream>
#include <cmath>
#include <string>
using namespace std;
// The area of an arbitrary triangle can be computed using the formula:
// where a, b, and c are the lengths of the sides, and s is the semiperimeter: 
// Write a void function that uses five parameters: three value parameters that 
// provide the lengths of the edges and two reference parameters that compute the 
// area and perimeter (not the semiperimeter). Make your function robust. Note 
// that not all combinations of a, b, and c produce a triangle. Your function 
// should produce correct results for legal data and reasonable results for illegal 
// combinations.

void math(double, double, double , double&, double&);


int main(){
  double a , b , c , area, perimeter;
  char answer;
  math(a , b , c , area , perimeter);
  
  cout << "The Area of the Triangle is: " << area << endl;
  cout << "The Perimeter of the Triangle is: " << perimeter << endl;
  
  return 0;
}


void math(double a, double b, double c, double& area, double&perimeter){
  double s;
  double n;
  char answer ='y';
  cout << "Press 'y' to start" << endl ;
  cin >> answer;
  if (answer == 'y'){
    cout << "Enter a value for the first triangle length: " << endl;
    cin >> a;
    cout << "Enter a value for the second triangle length: " << endl;
    cin >> b;
    cout << "Enter a value for the third triangle length: " << endl;
    cin >> c;
    if (a + b < c || a + b == c ){
        cout << "Invalid Triangle Please Try Again!" << endl;
           area = 0;
           perimeter = 0;
        return;

    }
    else{
    s = (a + b + c) / 2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    perimeter = a + b + c;
    }
  }

}