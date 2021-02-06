// Class: CMSC140 
// Instructor: Margaret Tseng
// Description: 
// Program Name:   HotelCalc.cpp
// Due: 8/2/20
// Platform/Compiler: Windows 7, Microsoft Visual Studio 2013
/* I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
      
   Print your Name here: Alexander Ortunio
*/

// Input:
//  1. location
//  2. floors
//  3. total rooms
//  4. room types
// Output:
//  1. Income 
//  2. Total rooms
//  3. Occupied rooms
//  4. Unoccupied rooms
//  5. Occupancy rate
//  6. Floor with least number of rooms
//  7. message about improving occupancy if below 60%
// Process/Algorithm:
//  1. gather input into repective variables/array
//  2. using a nested for loop calculate total income in addition to all other occupancy based stats
//  3. Output the data into a ok looking table

#include <iostream>
#include <iomanip>
//#include <string>
using namespace std;

int end_sequence(void);
void vertical_break(void);
void welcome_statement(void);

// price to stay per night
const int single_room = 60;
const int double_room = 75;
const int king_room = 100;
const int suite_room = 150;


int main()
{
    // inital questions
    int floors, rooms;
    //char location_of_hotel[50];

    int hotel_income, smallest_floor=-1, total_rooms=0, occupied_rooms=0;

    welcome_statement();
    
    cout << "Enter the location of this hotel chain: ";
    cin.getline(location_of_hotel, 50);
    //cout << "          BlueMont Hotel located in " << location_of_hotel << "\n";

    cout << "Enter the total number of floors of the hotel: ";
    cin >> floors;
    while(floors <= 0 || floors >= 6){
        cout << "!! Invalid Input. Number of floors should be between 1-5 !!\n";
        cin >> floors;
    }

// first value is number of rooms on the floor, the next four values represent the room types that are occupied
    int number_of_room_types[floors-1][5];

    for(int i = 1; i <= floors; i++){
        cout << "Enter the total number of rooms in the " << i << "th floor: ";
        cin >> number_of_room_types[i-1][0];

        while(number_of_room_types[i-1][0] <= 0 || number_of_room_types[i][0] >= 31){
            cout << "Invalid Input. Please input value between 1-30\n";
            cout << "Enter the total number of rooms in the " << i << "th floor: ";           
            cin >> number_of_room_types[i-1][0];
        }
        for(int j = 1; j < 5; j++){
            cout << "How Many " << (j==1 ? "SINGLE" : j==2 ? "DOUBLE" : j==3 ? "KING" : "SUITE") << " are occupied in the "<< i << "th floor: "; 
            cin >> number_of_room_types[i-1][j];
       }
    }

// calculate total income
    for(int i = 0; floors > i; i++){
        total_rooms += number_of_room_types[i][0];
        if((smallest_floor == -1) || (number_of_room_types[i][0] > number_of_room_types[smallest_floor][0]));
            smallest_floor = i;
        for(int j = 1; j < 5; j++){
            hotel_income += number_of_room_types[i][j] * (j==1 ? single_room: j==2 ? double_room : j ==3 ? king_room :  suite_room);
            occupied_rooms += number_of_room_types[i][j];
        }

    }

    cout << "\n\n\n";
    vertical_break();
    cout << "          BlueMont Hotel located in " <<  " *Location*";
    cout << "\n\n                  TODAY'S ROOM RATES<USD/night>\n";
    cout << "     SINGLE     DOUBLE     KING     SUITE\n";
    cout << "     " << single_room << "         " << double_room << "         " << king_room << "      " << suite_room << "\n";
    vertical_break();
    cout << "\nHotel Income: " << hotel_income << "";
    cout << "\nTotal Number of Rooms: " << total_rooms;
    cout << "\nTotal Number of Occupied Rooms: " << occupied_rooms;
    cout << "\nTotal Number of Unoccupied Rooms: " << total_rooms- occupied_rooms;
    cout << "\nOccupancy Rate: " << fixed << setprecision(2) << ((float)occupied_rooms/total_rooms)*100 << "%\n";

    cout << "\n" << smallest_floor << "st Floor with " << number_of_room_types[smallest_floor][0] << " rooms has the least # of rooms.";
    if( .6 >= ((float)occupied_rooms/total_rooms)){
        cout << "\nNeed to improve hotel occupancy!";
    }
    // dsa
    end_sequence();
	return 0;
}

void vertical_break(){
    cout << "=========================================================================\n";
}

void welcome_statement(){
    vertical_break();
    cout << "                          BlueMont Hotel\n";
    vertical_break();
}

int end_sequence(){
    cout << "\n\nThank you for testing my program!!\nPROGRAMMER: Alex Ortunio\nCMSC140 Common Project 3\nDue Date: 8/2/20\n";
    return(0);
}