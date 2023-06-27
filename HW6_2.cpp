//Problem 2 on page 613 of textbook.
// The formula for computing the number of ways of choosing
// r different things from a set of n things is the 
// following: C(n, r) = n!/(r!*(n - r)!)
//  The factorial function n! is defined by
// n! = n*(n-1)*(n-2)*...*1
//  Discover a recursive version of the formula for C(n, r) and write a 
//  recursive function that computes the value of the 
//  formula. Embed the function in a program and
// test it.
#include <iostream>
using namespace std;
int C(int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    } else {
        return C(n - 1, r - 1) + C(n - 1, r);
    }
}

int main() {
    int n, r;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of r: ";
    cin >> r;

    int result = C(n, r);
    cout << "C(" << n << ", " << r << ") = " << result << endl;

    return 0;
}
