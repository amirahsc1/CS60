#include<iostream>
#include<string>
using namespace std;
class zip_code{
private:
    int zipcode;
    string get_string(int num){
        string str = "";
        if(num == 0) {
            return "11000";}
        if(num>7){
            str.append("1");
            num = num-7;}
        if(num>4){
            str.append("1");
            num = num-4;}
        if(num>2){
            str.append("1");
            num = num-2;}
        if(num>1){
            str.append("1");
            num = num-1;}
        else{
            str.append("0");}
        return str;}
public:
    zip_code(int barcode);
    zip_code(string barcode);
    string getZipcode();
    int get_zipCode();

};
int main(){
zip_code myObj1(95053);
zip_code myObj2(77477);
cout << myObj1.getZipcode() << endl;
cout << myObj2.getZipcode() << endl;
return 0;
}
    
zip_code::zip_code(int barcode){
        zipcode = barcode;
}
zip_code::zip_code(string barcode){
    int zipper = 0;
    string var = barcode.substr(1,barcode.length()-2);
    for(int i=0; i<var.length()-5; i+=5){
        int x = 0;
        x = 7*(var[i]-'0') +
        4*(var[i+1]-'0') +
        2*(var[i+2]-'0') +
        1*(var[i+3]-'0');
        if(x == 11) {
        x = 0;
        zipper = zipper*10 + x;
        zipcode = zipper;
        }
}
}
int zip_code::zip_code::get_zipCode(){
return zipcode;
}

string zip_code::getZipcode(){
string str = "1";
int num1 = zipcode/10000;
int num2 = (zipcode - num1*10000)/1000;
int num3 = (zipcode - num1*10000-num2*1000)/100;
int num4 = (zipcode - num1*10000-num2*1000-num3*100)/10;
int num5 = (zipcode - num1*10000-num2*1000-num3*100-num4*10);
str.append(get_string(num1));
str.append(get_string(num2));
str.append(get_string(num3));
str.append(get_string(num4));
str.append(get_string(num5));
str.append("1");
return str;
}
