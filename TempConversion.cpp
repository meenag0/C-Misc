
// TempConversion.cpp

/* 
 Title: TempConversion.cpp
 Description: A simple program to convert temperatures between Fahrenheit and Celsius based on user input
 Date: March 22, 2024
 Author: Meena Gopalakrishnan
 Version: 1.0
 Copyright: 2024 Meena Gopalakrishnan
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	This program allows users to convert temperatures between Fahrenheit and Celsius.
 	It demonstrates basic input/output operations, conditional statements, and function calls.

 Compile: g++ -o TempConversion TempConversion.cpp
 Execution: ./TempConversion or ./TempConversion.exe
 
 Notes:
 	- The program expects the user to input a temperature value followed by a unit (F for Fahrenheit, C for Celsius).
 	- It then converts the temperature to the other unit and displays the result.
 	- The program continues to prompt the user for conversions until they choose to exit.
*/


/*

TEST PLAN

Normal case:
    > Please enter your temperature: 32
    > Please enter the units (F/C): F
    A temperature of 32 degrees Fahrenheit is equivalent to 0 degrees Celsius.
    Do you want another conversion (Y/N)? N
    Thank you for playing.

Bad Data case 1 (Invalid unit)
    > Please enter your temperature: 32
    > Please enter the units (F/C): K
    Please enter a valid input.
    Please enter your temperature: 32
    > Please enter the units (F/C): F
    A temperature of 32 degrees Fahrenheit is equivalent to 0 degrees Celsius.
    Do you want another conversion (Y/N)? N
    Thank you for playing.

Bad Data case 2 (Invalid temperature)
    > Please enter your temperature: abc
    Please enter the units (F/C): 
    Invalid inputs provided.
    Thank you. Goodbye.

    Discussion:
    - The program accepts temperatures in both Fahrenheit and Celsius.
    - Invalid units result in a prompt to enter a valid input.
    - Invalid temperature inputs are handled gracefully, but still produce a conversion.
    - The program loops until the user chooses to exit.

*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

int main() {
    char choice;
    do {
        double temperature;
        char unit;

        // Input temperature and unit from the user
        cout << "Please enter your temperature: ";
        cin >> temperature;
        cout << "Please enter the units (F/C): ";
        cin >> unit;

        double convertedTemperature;
        string fromUnit, toUnit;

        // Convert temperature based on the unit entered
        if (tolower(unit) == 'f') {
            convertedTemperature = fahrenheitToCelsius(temperature);
            fromUnit = "Fahrenheit";
            toUnit = "Celsius";
        } else if (tolower(unit) == 'c') {
            convertedTemperature = celsiusToFahrenheit(temperature);
            fromUnit = "Celsius";
            toUnit = "Fahrenheit";
        } else {
            // If the unit entered is invalid, prompt the user and continue the loop
            cout << "\nInvalid inputs provided." << endl;
            continue;
        }

        // Output the converted temperature
        cout << "A temperature of " <<  temperature << " degrees " << fromUnit << " is equivalent to "  << convertedTemperature << " degrees " << toUnit << "." << endl;

        // Ask if the user wants to do another conversion
        cout << "Do you want another conversion? (Y/N): ";
        cin >> choice;
    } while (tolower(choice) == 'y');

    // Say goodbye when the loop ends
    cout << "Thank you. Goodbye." << endl;

    return 0;
}
