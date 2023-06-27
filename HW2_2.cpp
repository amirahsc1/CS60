#include <iostream>


using namespace std;

struct Fraction{
  double num1 = 0.0 , num2 = 0.0;
  double den1 = 0.0 , den2 = 0.0;
  int finalNum = 0 , finalDen = 0;
  double sum = 0.0;
  double product = 0.0;
};

void printFraction(Fraction& createFraction);
void fractionAdd(Fraction& productFraction);
void fractionMulti(Fraction& sumFraction);
int findGCD(int n1, int n2);

int main(){
Fraction myFraction;
printFraction(myFraction);
fractionAdd(myFraction);
fractionMulti(myFraction);

return 0;
}

void printFraction(Fraction& createFraction){
  cout << "Input the Numerator of your first of Fraction: ";
  cin >> createFraction.num1;
  cout << "Input the Denominator of your first of Fraction: ";
  cin >> createFraction.den1;
  cout << "Input the Numerator of your Second of Fraction: ";
  cin >> createFraction.num2;
  cout << "Input the Denominator of your Second of Fraction: ";
  cin >> createFraction.den2;
}

void fractionAdd(Fraction& sumFraction){
  sumFraction.finalDen = (sumFraction.den1 *sumFraction.den2) / findGCD(sumFraction.den1, sumFraction.den2);
  sumFraction.sum = (sumFraction.num1 * (sumFraction.finalDen/sumFraction.den1)) + (sumFraction.num2 *(sumFraction.finalDen/sumFraction.den2));
  sumFraction.finalNum = sumFraction.sum/ findGCD(sumFraction.sum, sumFraction.finalDen);
  sumFraction.finalDen = sumFraction.finalDen/findGCD(sumFraction.sum,sumFraction.finalDen);
  cout << "The sum of your two fractions are: " << sumFraction.finalNum << '/'<< sumFraction.finalDen<< endl;
}


void fractionMulti(Fraction& productFraction){
  productFraction.finalDen = productFraction.den1 * productFraction.den2;
  productFraction.finalNum = productFraction.num1 * productFraction.num2;
  cout << "The product of your two fraction:  " << productFraction.finalNum << '/' << productFraction.finalDen << endl;
}

int findGCD(int n1, int n2)
{
	int gcd;
	for(int i=1; i <= n1 && i <= n2; i++)
    {
        if(n1%i==0 && n2%i==0)
            gcd = i;
    }
	return gcd;
}