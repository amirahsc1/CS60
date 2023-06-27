//Problem 6 on page 614 of textbook.
#include <iostream>
#include <chrono>
using namespace std;

int fibonacciIterative(int n) {
    if (n <= 1)
        return n;
    int fib0 = 1;
    int fib1 = 1;
    int fib;
    for (int i = 2; i <= n; ++i) {
        fib = fib0 + fib1;
        fib0 = fib1;
        fib1 = fib;
    }
    return fib;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    auto start = chrono::steady_clock::now();
    int result = fibonacciIterative(n);
    auto end = chrono::steady_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "The " << n << "th Fibonacci number is: " << result << std::endl;
    cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    return 0;
}
