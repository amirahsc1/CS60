#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
static const int CAPACITY = 20;
class biguint{
private:
    unsigned short data_[CAPACITY];
public:
    biguint(){ //Default Constructor
        for (int i = 0; i < CAPACITY; i++) {
            data_[i] = 0; //Filling the Arrays with Zeros
            }
    };
   biguint(string s){
        //Getting the length of the string
        int len = s.size();
        int ii = 0;
        for (int i = len - 1 ; i >= 0 && ii < CAPACITY; i--) {
            data_[ii++] = s[i] - '0'; // convert each char into a number   
             }
    };
    unsigned short operator [] (int pos){ //returning the full array
        return data_[pos];
    };
    
    void operator += (biguint b){
        int num = 0;
        for (int i = 0; i < CAPACITY; i++) {
            int sum = data_[i] + b.data_[i] + num;
            data_[i] = sum % 10;
            num = sum / 10;
        }
    };

};

int main(){
    //Calling Default Constructor
    biguint myObj1; 
    //Calling Constructor that takes in a string
    biguint myObj2("1234"); 
    biguint myObj3("1234");
    //Calling [] Operator
    cout << myObj2[0] << " " << myObj2[1] << " " << myObj2[2] << " " << myObj2[3] <<endl; 
    //Calling += Operator
    myObj1 += myObj3; 
    cout << myObj1[0] << " " << myObj1[1] << " " << myObj1[2] << " " << myObj1[3] << endl; 

    return 0;
}