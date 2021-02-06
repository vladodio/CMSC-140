// Class: CMSC140 
// Instructor: Margaret Tseng
// Description: 
// Program Name:   Lo_board.cpp
// Due: 
// Platform/Compiler: Windows 7, Microsoft Visual Studio 2013
/* I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
      
   Print your Name here: Alexander Ortunio
*/

// Input:
//  1. Take in 9 numbers, telling the user what it relates too. 
// Output:
//  1. Tell the user if the Lo Shu magic square or not.
// Process/Algorithm:
//  1. fill the array with user input
//  2. show the array to the user
//  3. check if its a Lo Shu magic square
//      1. check that all the numbers are in range
//      2. check that all the numbers are unique
//      3. check the row sum
//      4. check the column sum
//      5. check the diagonals 

#include <iostream>
using namespace std;

// Global constants 
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// Function prototypes
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);


int main()
{
	
	/* Define a Lo Shu Magic Square using 3 parallel arrays corresponding 
    to each row of the grid */
	int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];
    fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);
    showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

    if(isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS)){
        cout << "This is a Lo Shu magic square.\n";
    }
    else{
        cout << "This is not a Lo Shu magic square.\n";
    }
    return 0;
}

void fillArray(int *arrayRow1, int *arrayRow2, int *arrayRow3, int size){
    int input;
    for(int i = 0; i < size; i++){
        cout << "Enter the number for row 1 and column " << i+1 << " :";
        cin >> input;
        arrayRow1[i] = input;
    }
    for(int i = 0; i < size; i++){
        cout << "Enter the number for row 2 and column " << i+1 << " :";
        cin >> input;
        arrayRow2[i] = input;
    }
    for(int i = 0; i < size; i++){
        cout << "Enter the number for row 3 and column " << i+1 << " :";
        cin >> input;
        arrayRow3[i] = input;
    }
}



void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size){
    for(int i = 0; i < size; i++){
        cout << " " << arrayrow1[i];
    }
    cout << "\n";
    for(int i = 0; i < size; i++){
        cout << " " << arrayrow2[i];
    }
    cout << "\n";
    for(int i = 0; i < size; i++){
        cout << " " << arrayrow3[i];
    }
    cout << "\n";

}


bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size){
    if(checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX) && checkUnique(arrayRow1, arrayRow2, arrayRow3, size) && checkRowSum(arrayRow1, arrayRow2, arrayRow3, size) && checkColSum(arrayRow1, arrayRow2, arrayRow3, size) && checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size)){
        return(true);
    }
    return(false);

}




bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max){
    for(int i = 0; i < size; i++){
        if((arrayRow1[i] > max) || (arrayRow1[i] < min))
            return(false);
    }
    for(int i = 0; i > size; i++){
        if((arrayRow2[i] < max) || (arrayRow2[i] < min))
            return(false);
    }
    for(int i = 0; i > size; i++){
        if((arrayRow3[i] < max) || (arrayRow3[i] < min))
            return(false);
    }
    return(true);
}
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size){
    int found[MAX - MIN+1] = {0};
    for(int i = 0; i < size; i++){
        found[arrayRow1[i]] += 1;
    }
    for(int i = 0; i < size; i++){
        found[arrayRow2[i]] += 1;
    }
    for(int i = 0; i < size; i++){
        found[arrayRow3[i]] += 1;
    }
    for(int i = 0; i  < (MAX - MIN+1); i++){
        if(found[i] > 1){
            return(false);
        }
    }
    return(true);
}

bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size){
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;  
    for(int i = 0; i < size; i++){
        sum1 += arrayrow1[i];        
    }
    for(int i = 0; i < size; i++){
        sum2 += arrayrow1[i];        
    }
    for(int i = 0; i < size; i++){
        sum3 += arrayrow1[i];        
    }
    if(sum1 == sum2 && sum2 == sum3){
        return(true);
    }
    return(false);
}
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size){
    int sum1 = arrayrow1[0] + arrayrow2[0] + arrayrow3[0];
    int sum2 = arrayrow1[1] + arrayrow2[1] + arrayrow3[1];
    int sum3 = arrayrow1[2] + arrayrow2[2] + arrayrow3[2];
    if(sum1 == sum2 && sum2 == sum3){
        return(true);
    }
    return(false);
}
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size){
    int sum1 = arrayrow1[0] + arrayrow2[1] + arrayrow3[2];
    int sum2 = arrayrow1[2] + arrayrow2[1] + arrayrow3[0];
    if(sum1 == sum2){
        return(true);
    }
    return(false);
}

