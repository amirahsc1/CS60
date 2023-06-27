#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Overload Function = Function of the same name but different parameters
double convertToMPH(int minutes, int seconds);
double convertToMPH(double kph);

int main()
{

    int minutes=0,seconds=0;
    double kph=0;
    char ans = 'y';
    // Didn't know what a driver function was so I wrote the code for user input 
    // Cause I wrote it already decided  to keep it but I know that wasn't what was aske
    cout << "What it your MPH?" << endl;
    cout << "In order to find out what your MPH is, enter your pace in minutes/seconds or KPH" << endl;
    cout <<"For Example:" << endl;
    cout <<"A 7 minute and 23 second mile is a " << convertToMPH(7, 23) << " in MPH" << endl;
    cout <<"A 5 minute and 34 second mile is a " << convertToMPH(5, 34) << " in MPH" << endl;
    cout <<"Your KPM is: 20, making your mph: " << convertToMPH(20) << endl; 
    cout <<"Your KPM is: 31, making your mph: " << convertToMPH(31) << endl;
    while(ans=='Y'||ans=='y'){
        cout<<"Enter minutes: ";
        cin>>minutes;
        cout<<endl<<"Enter seconds: ";
        cin>>seconds;

        cout<<endl<<"Miles per Hour is: "<<
              convertToMPH(minutes,seconds)<<endl<<endl;

        cout<<"Enter kilometers per hour: ";
        cin>>kph;
        cout<<endl<<"Miles per Hour is: "<<
              convertToMPH(kph)<<endl;

        cout<<"Test again?(y/n) ";
        cin>>ans;
        cout<<endl;

    }

    return 0;
}

double convertToMPH(int minutes, int seconds)
{
    double totalMins=minutes+(seconds/60.0);
    return(60.0/totalMins);

}

double convertToMPH(double kph)
{
    const double milesToKM = 1.61;
    return(kph/milesToKM);
}
