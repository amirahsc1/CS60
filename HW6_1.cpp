// Problem 1 on page 613 of textbook.
// Write a recursive function definition for a function that has one parameter n of
// type int and that returns the nth Fibonacci number. The Fibonacci numbers are
// F0 is 1, F1 is 1, F2 is 2, F3 is 3, F4 is 5, and in general
// Fi+2 = Fi + Fi+1 for i = 0, 1, 2, …
#include <iostream>
#include <chrono>
using namespace std;
int fibonacci(int n) {
    if (n <= 1) {
        return 1;
    } 
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    auto start = chrono::steady_clock::now();

    int result = fibonacci(n);

    auto end = chrono::steady_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "The " << n << "th Fibonacci number is: " << result << std::endl;
    cout << "Time taken: " << duration.count() << "s" << std::endl;

    return 0;
}