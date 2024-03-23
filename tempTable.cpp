// tempTable.cpp

/*
 Title: tempTable.cpp
 Description: Printing out temperature convertions from Farenheit to Celsius and vice versa using a properly formatted table for temperatures from -40 to 455 in increments of 5degrees.
 Date: March 22, 2024
 Author: Meena Gopalakrishnan
 Version: 1.0
 Copyright: 2024 Meena Gopalakrishnan
*/


/*
DOCUMENTATION

Program Purpose:
    - This program converts temperatures between Celsius and Fahrenheit and prints a temperature conversion table.

Compile:
    - Command: g++ -o tempTable tempTable.cpp

Execution:
    - Command: ./tempTable or tempTable.exe

Notes: 
    - The program generates a temperature conversion table for temperatures ranging from -40°C to 455°C, with conversions every 5 degrees.
    - Temperature conversions are performed using the formulas: 
        - Fahrenheit to Celsius: (F - 32) * 5 / 9
        - Celsius to Fahrenheit: (C * 9 / 5) + 32
    - The program utilizes fixed precision with three decimal places for output formatting.
    - The table displays temperatures in both Fahrenheit and Celsius columns.

Classes: 
    - None

Functions:
    - CtoF(double i): double
        - Purpose: Converts temperature from Celsius to Fahrenheit.
        - Parameters: 
            - i: double - Temperature in Celsius.
        - Returns:
            - double - Temperature converted to Fahrenheit.

    - FtoC(double i): double
        - Purpose: Converts temperature from Fahrenheit to Celsius.
        - Parameters: 
            - i: double - Temperature in Fahrenheit.
        - Returns:
            - double - Temperature converted to Celsius.

Variables:
    - i: double
      Purpose: Used as a loop variable to iterate through temperatures from -40°C to 455°C.

*/

/*
TEST PLAN

Normal case:

    - Program is executed and prints prime number from 1 to 10000:

    Expected Output:
        Temperature    |     Temperature 
         (degrees)     |      (degrees) 
        F        C     |     C        F    
       -40       -40   |    -40     -40   
       -35       -37   |    -35     -31   
       -30       -34   |    -30     -22   
       -25       -31   |    -25     -13   
       -20       -28   |    -20      -4   
       -15       -26   |    -15       5   
       -10       -23   |    -10      14   
        -5       -21   |     -5      23   
         0       -18   |      0      32   
        continued...

*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function to convert Celsius to Fahrenheit
double CtoF(double i){
    double CtoFResult = ((i * 9) / 5) + 32;
    return CtoFResult;
}

// Function to convert Fahrenheit to Celsius
double FtoC(double i){
    double FtoCResult = (i - 32 ) * 5 / 9;
    return FtoCResult;
}

int main(){
    // Set precision for output formatting
    std::cout << std::fixed << std::setprecision(3);

    // Display header for the temperature conversion table
    cout << "     Temperature    |     Temperature " << endl;
    cout << "      (degrees)     |      (degrees) " << endl;
    cout << "     F        C     |     C        F    " << endl;

    // Initialize temperature variable
    double i = -40;
    
    // Iterate through temperatures and print conversion table
    while(i < 456){
        // Print temperature conversion table with appropriate formatting
        cout << std::setw(9) << i << std::setw(9) << FtoC(i) <<  "  |" << std::setw(9) << i << std::setw(9) << CtoF(i) << endl;
        
        // Increment temperature for the next iteration
        i = i + 5;
    }

    return 0;
}