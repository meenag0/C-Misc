// primeNum.cpp

/*
 Title: primeNum.cpp
 Description: Printing all prime number up to 10,000
 Date: March 22, 2024
 Author: Meena Gopalakrishnan
 Version: 1.0
 Copyright: 2024 Meena Gopalakrishnan
*/


/*
DOCUMENTATION

Program Purpose:
    - This program generates prime numbers up to 10,000 and prints them.

Compile:
    - Command: g++ -o primeNum primeNum.cpp

Execution:
    - Command: ./primeNum or ./primeNum.exe

Notes: 
    - This program iterates through numbers from 1 to 9999 and checks each number's divisibility to determine if it is prime.
    - For efficiency, it only checks divisibility up to the square root of the number being tested.
    - Prime numbers are printed separated by commas.
    - The program terminates after printing all prime numbers up to 10,000.

Classes: 
    - None

Variables:
    - i: int
      Purpose: Used as a loop variable to iterate through numbers from 1 to 9999.
      
    - j: int
      Purpose: Used as a loop variable to check divisibility of numbers.
      
    - checkPrime: bool
      Purpose: Used to determine if a number is prime.

*/

/*
TEST PLAN

Normal Case:
    - Action:
        - Execute the program.
    - Expected Output:
        - The program prints all prime numbers up to 10,000 separated by commas.

          1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, ....

Discussion:
    - The program generates prime numbers within the range of 1 to 10,000.
    - It checks each number's primality by testing divisibility with all numbers from 2 to the number itself minus 1.
    - Prime numbers are printed separated by commas without any additional formatting.

*/


#include <iostream>
using namespace std;

int main() {
    // Print the title
    cout << "Prime Numbers:" << endl;

    // Iterate through numbers from 1 to 9999
    for (int i = 1; i < 10000; i++) {
        bool checkPrime = true;

        // Check if the current number is prime
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                // If the number is divisible by any other number than 1 and itself, it's not prime
                checkPrime = false;
                break;
            }
        }

        // If the number is prime, print it
        if (checkPrime == true) {
            cout << i << ", ";
        }
    }
    return 0;
}
