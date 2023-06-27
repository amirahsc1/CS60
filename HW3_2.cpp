// 3. Write a program that accepts a C-string input from the user and reverses the contents of the string. Your program should work by using two pointers. The “head”
// pointer should be set to the address of the first character in the string, and the
// “tail” pointer should be set to the address of the last character in the string (i.e., the
// character before the terminating null). The program should swap the characters
// referenced by these pointers, increment “head” to point to the next character, decrement “tail” to point to the second-to-last character, and so on, until all characters
// have been swapped and the entire string reversed.

#include<iostream>
#include<cstring>
using namespace std;
static const int CAPACITY = 30;
string reverse(char myString[CAPACITY]);
int main(){
char yourString[CAPACITY];
cout << "enter a String: ";
cin >> yourString;
string output = reverse(yourString);
cout <<"Reverse string : "<< output << endl;
return 0;
}
string reverse(char myString[CAPACITY]){
char a = 'a';
char b = 'b';
char *head = &a;
char *tail = &b;
for (int i = 0; i< (strlen(myString) / 2); i++){
    *head = myString[i];
    *tail = myString[strlen(myString) - 1 - i];
    myString[i] = *tail;
    myString[strlen(myString) - 1 - i] = *head;
}
return myString;

}