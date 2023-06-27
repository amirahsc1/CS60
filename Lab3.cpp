#include <iostream>
# include <string>
# include <cmath>
using namespace std;
// Youre dividing the length of the array by the length plus 

class  ModInt{
    private:
    int mod;
    int value;
    public:
    //Declartations
    ModInt(int num1, int num2);
    ModInt();
    // I made this change in respsonse to the error message this isn't the issue
    bool operator ==(ModInt lhs, ModInt rhs);
    void operator+=(ModInt rhs);
    void operator +(ModInt lhs, ModInt rhs);
    int getMod(){
        return mod;}
int getValue(){
    return value;}
};
//Defintion
ModInt::ModInt(){ 
    mod = 0;
    value = 0;
}

ModInt::ModInt(int num1, int num2){ 
   mod = num1;
   value = num2;
}
bool operator ==(ModInt lhs, ModInt rhs){
   if (lhs.getValue() == rhs.getValue() && lhs.getMod() == rhs.getMod() ){
    return true;
   }
   return false;
}

void ModInt::operator +=(ModInt rhs){
    if (mod == rhs.getMod()){
    value = (value + rhs.getValue()) % mod;
    }
        mod = -1;
        value = -1;
}
void ModInt::operator +(ModInt lhs, ModInt rhs){
if(lhs.getMod() == rhs.getMod()){
    value = (lhs.getValue() + rhs.getValue()) % rhs.getMod();
}
mod = -1;
value = -1;
}

int main() {
    
 ModInt myObj;
 ModInt myObj2 = ModInt(4, 8);
 ModInt myObj3 = ModInt(4, 11);
 ModInt myObj4;
 //The ay I'm calling the + and += operator could be the problem
 myObj4 = myObj2 + myObj3;
 ModInt myObj6 = ModInt(0, 0);
 ModInt myObj7 = ModInt(3,8);
 ModInt myObj9 = ModInt(0, 12);
 ModInt myObj10;
 myObj10 = myObj7 + myObj9;
 ModInt myObj11 += myObj9;
 //Default Mod and Value as defined in my class
 // Those values are Mod = 0 and Value = 0
cout <<"Mod = " << myObj.getMod() << endl;
cout <<"Value = " << myObj.getValue() << endl;
// Mod and Value Chosen in Main Function
// mod = 4 and value = 8
cout <<"Mod = " << myObj2.getMod() << endl;
cout <<"Value = " << myObj2.getValue() << endl;
//Should print out a 0 for False
//Orginally for the code I was calling it like this:
// bool equal = myObj == myObj2;
cout <<  myObj == myObj2 << endl;
//Should print out a 1 for true
cout << myObj == myObj6 << endl;
// Should print out a value
cout <<"Mod = " << myObj11.getMod()  << endl;
cout <<"Value = " << myObj11.getValue() << endl;
//Should print out -1
cout <<"Mod = " << myObj3.getMod() << endl;
cout << "Value = " << myObj3.getValue() << endl; 
// Should print out a value
cout <<"Mod = " << myObj4.getMod()  << endl;
cout <<"Value = " << myObj4.getValue() << endl;
//Should print out -1
cout <<"Mod = " << myObj10.getMod() << endl;
cout << "Value = " << myObj10.getValue() << endl; 
return 0;
}

