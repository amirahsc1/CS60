//Problem 7 on page 615 of textbook.
#include <iostream>
#include <chrono>
using namespace std;
int fibonacci(int n, int* arr) {
    if (n <= 1) {
        return 1;
    }
    if (arr[n] != 0) {
        return arr[n];
    }
    arr[n] = fibonacci(n - 1, arr) + fibonacci(n - 2, arr);
    return arr[n];
}

int fibonacci(int n) {
    int* arr = new int[n + 1];
    for (int i = 0; i <= n; ++i) {
        arr[i] = 0;
    }
    int result = fibonacci(n, arr);
    delete[] arr;
    return result;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    auto start = chrono::steady_clock::now();

    int result = fibonacci(n);

    auto end = chrono::steady_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "The " << n << "th Fibonacci number is: " << result << endl;
    cout << "Time taken: " << duration.count() << "s" << endl;

    return 0;
}
