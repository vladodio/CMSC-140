// Class: CMSC140 
// Instructor: Margaret Tseng
// Description: Project two submission 
// Program Name:   converter.cpp
// Due: 7/26/20
// Platform/Compiler: Windows 7, Microsoft Visual Studio 2013
/* I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
      
   Print your Name here: Alexander Ortunio
*/

// Input:
//  1. User must enter country
//  2. User must enter menu option
//  3. User must enter temperature in Celsius
//  4. User must enter distance in kilometers
//  5. User must enter weight in kilograms
// Output:
//  1. A menu displaying program options
//  2. The temperature in appropriate units(Fahrenheit)
//  3. The distance in appropriate units(miles)
//  4. The weight in appropriate units(pounds)
//  5. A menu displaying program options
//  6. A menu displaying program options
// Process/Algorithm:
//  1. Take in user submitted country
//  2. Print out menu
//  3. take in result and run respective function in case function
//  4. do calculation, while catching bad input
//  5. print out results followed by exit message


#include <iostream>
//#include <cstring>
#include <iomanip>
using namespace std;

int user_input;
void temperature(void);
void distance(void);
void weight(void);
int main_menu(void);
int exit_sequence(void);



int main(){
    char country[50];
    cout << "Enter a country name: ";
    cin.getline(country, 50);    
    
    user_input = main_menu();
    switch(user_input){
        case 1: temperature(); break;
        case 2: distance(); break;
        case 3: weight(); break;
        case 4: cout << "Exiting...\n\n"; break;
        default: cout << "Invalid input.\n"; break;
    }

    cout << country << " sounds fun!";
    exit_sequence();
    return(0);
}



int main_menu(){
    int selection;
    cout << "\n\nConverter Toolkit\n--------------------\n    1. Temperature Converter\n    2. Distance Converter\n    3. Weight Converter\n    4. Quit\n\nEnter your choice (1-4): ";
    try{
        cin >> selection;
    }
    catch(...){
        cout << "Invalid input.\n";
    }
    return(selection);
}

void temperature(){
    int input;
    cout << "Please enter temperature in Celsius: ";
    try{
    cin >> input;
    cout << "It is " << ((int)((((float)9*input)/5)+32)) <<" in Fahrenheit.\n\n";
    }
    catch(...){
        cout << "Invalid input.\n";
    }

}

void distance(){
    int input;
    cout << "Please enter distance in Kilometers: ";
    try{
        cin >> input;
        if(input < 0){
            cout << "!! Program does not take negative distances !!\n\n";
        }
        else{
            cout << fixed;
            cout << setprecision(2);
            cout << "It is " << ((((float)input)*6.0)/10.0) <<" in Miles.\n\n";
        }
    }
    catch(...){
        cout << "Invalid input.\n";
    }
}

void weight(){
    int input;
    cout << "Please enter weight in Kilograms: ";
    try{
        cin >> input;
        if(input < 0){
            cout << "!! Program does not take negative weights !!\n\n";
        }
        else{
            cout << fixed;
            cout << setprecision(1);
            cout << "It is " << ((input * 2.2)) <<" in Miles.\n\n";
        }
    }
    catch(...){
        cout << "Invalid input.\n";
    }
}

int exit_sequence(){
    cout << "\n\nThank you for testing my program!!\nPROGRAMMER: Alex Ortunio\nCMSC140 Common Project 2\nDue Date: 7/26/20\n";
    return(0);
}