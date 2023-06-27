#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void math(double, double, double , double&, double&);


int main(){
  double a , b , c , area, perimeter;
  char answer;
  math(a , b , c , area , perimeter);
  cout << " The Area of the Triangle is: " << area << endl;
  cout << "The Perimeter of the Triangle is: " << perimeter << endl;

  return 0;
}


void math(double a, double b, double c, double& area, double&perimeter){
  double s;
  char answer ='y';
  cout << "If you wish to coutinue input 'y' if you want to inpute 'n'." ;
  cin >> answer;
  if (answer == 'y'){
    cout << "Enter a value for the first triangle length";
    cin >> a;
    cout << "Enter a value for the second triangle length";
    cin >> b;
    cout << "Enter a value for the third triangle length";
    cin >> c;
    s = (a + b + c) / 2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    perimeter = a + b + c;
    
  }

}
