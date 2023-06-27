#include <iostream>
#include <string>
using namespace std;

//The program asks the user if he or she wants to convert lengths or weights. If the user chooses lengths,
// then the program asks the user if he or she wants to convert from feet and inches to meters and centimeters 
//or from meters and centimeters to feet and inches. If the user chooses weights, a similar question about 
// pounds, ounces,
//  kilograms, and grams is asked. The program then performs the desired conversion. Have the user respond 
//  by typing the integer 1 for one type of conversion and 2 for the other. The program reads the user’s 
//  answer and then executes an if-else statement. Each branch of the if-else statement will be a function 
//  call. The two functions called in the if-else statement will have function definitions that are very 
//  similar to the programs for Programming Projects 4.6 and 4.9. Thus, these functions will be fairly 
//  complicated function definitions that call other functions; however, they will be very easy to write 
//  by adapting the programs you wrote for Programming Projects 4.6 and 4.9. Notice that your program will 
//  have if-else statements embedded inside of if-else statements, but only in an indirect way. The outer 
//  if-else statement will include two function calls, as its two branches. These two function calls will 
//  each in turn include an if-else statement, but you need not think about that. They are just function 
//  calls and the details are in a black box that you create when you define these functions. If you try to
// create a four-way branch, you are probably on the wrong track. You should only need to think about 
// two-way branches (even though the entire program does ultimately branch into four cases). Include a
// loop that lets the user repeat this computation for new input values until the user says he or she
//  wants to end the program.

void whichConversion(int&, int& );
void input(double& ,double& ,int , int );
void calculation(double& , double& , double& , double& ,int ,int );
void output(double , double ,double , double ,int , int );

const double METER_TO_FOOT=0.3048;
const double CM_TO_M=100.0;
const double IN_TO_FT=12.0;

const double LB_TO_KG=2.2046;
const double G_TO_KG=1000.0;
const double OZ_TO_LB=16.0;

int main()
{
    char answer='y';

    while(answer=='Y'||answer=='y'){
           int measurment,measurment2;
           double value1, value2,value3,value4;
           whichConversion(measurment,measurment2);

           if(measurment==1){
               input(value1,value2,measurment,measurment2);
               calculation(value1,value2,value3,value4,measurment,measurment2);
               output(value1,value2,value3,value4,measurment,measurment2);
           }
           else{
               input(value1,value2,measurment,measurment2);
               calculation(value1,value2,value3,value4,measurment,measurment2);
               output(value1,value2,value3,value4,measurment,measurment2);
           }
           cout<<"Would you like to enter another value(Enter Y or y)?:";
           cin>>answer;
           cout<<endl;
       }

    return 0;
}


void whichConversion(int &measurment,int &measurment2)
{
    do{
        cout<<"Which type of conversion would you like to do?\n"
           <<"Enter 1 for weights or\n"
          <<"Enter 2 for lengths: ";
        cin>>measurment;

    }while( measurment ==0);

    if(measurment==1){
            cout<<"Which type of conversion would you like to do?\n"
               <<"Enter 1 for lb. and oz. to kg. and g. or\n"
              <<"Enter 2 for kg. and g. to lb. and oz.: ";
            cin>>measurment2;
    }

    else{
            cout<<"Which type of conversion would you like to do?\n"
                  <<"Enter 1 for ft. and in. to m. and cm. or\n"
                  <<"Enter 2 for m. and cm. to ft. and in.: ";
            cin>>measurment2;

    }
}


void input(double& value1, double& value2, int measurment, int measurment2)
{
       if(measurment==1){
           if(measurment2==1){
                    cout<<"Please enter how many lb. or lbs.: ";
                    cin>>value1;
                    cout<<"and how many ounce(s): ";
                    cin>>value2;

            }
            else{
                    cout<<"Please enter how many kilogram(s): ";
                    cin>>value1;
                    cout<<"and how many gram(s): ";
                    cin>>value2;

            }
       }
       else{
           if(measurment2==1){
               cout<<"Please enter how many feet or foot: ";
               cin>>value1;
               cout<<"and how many inch(es): ";
               cin>>value2;
           }

            else{
                    cout<<"Please enter how many meter(s): ";
                    cin>>value1;
                    cout<<"and how many centimeter(s): ";
                    cin>>value2;
                }
       }
}

void calculation(double& value1, double& value2, double& value3, double& value4,int measurment,int measurment2)
{//
    if(measurment==1){
        if(measurment2==1){
            value3=value1/LB_TO_KG;
            value4=((value2/OZ_TO_LB)/LB_TO_KG)*G_TO_KG;
        }
        else{
            value3=value1*LB_TO_KG;
            value4=((value2/G_TO_KG)*LB_TO_KG)*OZ_TO_LB;
        }
    }
    else{
        if(measurment2==1){
            value3=value1*METER_TO_FOOT;
            value4=(value2/IN_TO_FT)*METER_TO_FOOT*CM_TO_M;
        }
        else{
            value3=value1/METER_TO_FOOT;
            value4=((value2/CM_TO_M)/METER_TO_FOOT)*IN_TO_FT;
        }
    }
}

void output(double value1, double value2,double value3, double value4,int measurment,int measurment2)
{
    if(measurment==1){
        if(measurment2==1){
        cout<<"calculationed: "<<value1<<" LB. "<<value2<<" OZ. to"<<endl;
        cout<<value3<<" KG. "<<value4<<" G."<<" or "<<value3+(value4/G_TO_KG)<<" KG. "<<"or "<<(value3+(value4/G_TO_KG))*G_TO_KG<<" G."<<endl;
    }

    else{
        cout<<"calculationed: "<<value1<<" KG. "<<value2<<" G. to"<<endl;
        cout<<value3<<" LB. "<<value4<<" OZ."<<" or "<<value3+(value4/OZ_TO_LB)<<" LB. "<<"or "<<(value3+(value4/OZ_TO_LB))*OZ_TO_LB<<" OZ."<<endl;
       }
    }

    else{
        if(measurment2==1){
                cout<<"calculationed: "<<value1<<" ft. "<<value2<<" in. to"<<endl;
                cout<<value3<<" m. "<<value4<<" cm."<<" or "<<value3+(value4/CM_TO_M)<<" m. "<<"or "<<(value3+(value4/CM_TO_M))*CM_TO_M<<" cm."<<endl;
        }
        else{
                cout<<"calculationed: "<<value1<<" m. "<<value2<<" cm. to"<<endl;
                cout<<value3<<" ft. "<<value4<<" in. "<<"or "<<value3+(value4/IN_TO_FT)<<" ft. "<<"or "<<(value4+(value3*IN_TO_FT))<<" in."<<endl;
        }

    }
}
