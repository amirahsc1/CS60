// 1. Problem 3 on page 916 - part c graded only
#include <iostream>
#include <vector>
using namespace std;
void prime(int N){
    vector<bool> isPrime(N + 1, true); 
    for (int i = 2; i * i <= N; i++){
        if (isPrime[i]){
            for (int j = i * i; j <= N; j += i){
                isPrime[j] = false;
            }
        }
    }
    cout << "Prime numbers less than " << N << " are:\n";
    for (int i = 2; i <= N; i++){
        if (isPrime[i]){
            cout << i << " ";
        }
    }

    cout << endl;
}

int main(){
    int N;
    cout << "Enter a number N: ";
    cin >> N;
    prime(N);
    return 0;
}
