
// Assignment1Question2.cpp

/* 
 Title: Assignment1Question2.cpp
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

 Compile: g++ -o Assignment1Question2 Assignment1Question2.cpp
 Execution: ./Assignment1Question2 
 
 Notes:
 	- The program expects the user to input a temperature value followed by a unit (F for Fahrenheit, C for Celsius).
 	- It then converts the temperature to the other unit and displays the result.
 	- The program continues to prompt the user for conversions until they choose to exit or provide invalid data.
    - The program handles uppercase and lowercase inputs for unit selection.

Classes:
    None

Variables:
    - temperature: a double variable to store the temperature value entered by the user.
    - unit: a char variable to store the unit entered by the user (F for Fahrenheit, C for Celsius).
    - choice: a char variable to store the user's choice whether to perform another conversion.

Functions:
    - fahrenheitToCelsius(double fahrenheit): a function that takes a temperature value in Fahrenheit and returns its equivalent value in Celsius.
    - celsiusToFahrenheit(double celsius): a function that takes a temperature value in Celsius and returns its equivalent value in Fahrenheit.


*/


/*

TEST PLAN

Normal case:
    > Please enter your temperature: 32
    > Please enter the units (F/C): F
    A temperature of 32 degrees Fahrenheit is equivalent to 0 degrees Celsius.
    > Do you want another conversion? (Y/N): y
    > Please enter your temperature: 100
    > Please enter the units (F/C): C
    A temperature of 100 degrees Celsius is equivalent to 212 degrees Fahrenheit.
    > Do you want another conversion? (Y/N): N
    Thank you. Goodbye.


Bad Data case 1 (Invalid unit):
    > Please enter your temperature: 32
    > Please enter the units (F/C): K
    Invalid inputs provided.
    Thank you. Goodbye.

Bad Data case 2 (Invalid temperature):
    > Please enter your temperature: abc
    Please enter the units (F/C): 
    Invalid inputs provided.
    Thank you. Goodbye.

    Discussion:
    - The program accepts temperatures in both Fahrenheit and Celsius.
    - Invalid units and invalid temperatures result in exiting the code, and ending the program.
    - The program loops until the user chooses to exit, or enters an invalid value.

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