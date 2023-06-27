#include <iostream>
using namespace std;
template <typename T>
int count_exact(T a[], int size, T find){
    int count = 0;
    for(int i = 0; i < size; i++){
        if (a[i] == find){
            count++;
        }
    }
     return count;
}

template <typename T>
int count_range(T a[], int size, T low, T high){
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] >= low && a[i] <= high) {
            count++;
        }
    }
    return count;
}
int main(){
    //Calling count_exact function
    int a_1[] = {6, 2, 3, 2, 6, 4};
    int count = count_exact<int>(a_1, 6, 2);
    if(count == 0){
       cout<< "This value does does not appear in this array." << endl;
    }
    else{
        cout <<"This value appears in this array " << count << " times." << endl;
    }
    
    string a_2[] = {"dog", "cat", "frog", "dog", "fish", "dog"};
    int count_2 = count_exact<string>(a_2, 6, "dog");
    if(count_2 == 0){
       cout<< "This string does does not appear in this array." << endl;
    }
    else{
        cout <<"This string appears in this array " << count_2 << " times." << endl;
    }
    //Calling count_range function
    int count_3 = count_range(a_1, 6, 2, 4);
    if(count_3 == 0){
        cout <<"There are no values between 2 and 4" << endl; 
    }
    else{
        cout << "This is the number of values between 2 and 4: " << count << endl;
    }

    return 0;
}