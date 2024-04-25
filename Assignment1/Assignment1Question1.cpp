
// Assignment1Question1.cpp

/*
 Title: Assignment1Question1.cpp
 Description: Printing a properly formatted multiplication table for 12.
 Date: March 22, 2024
 Author: Meena Gopalakrishnan
 Version: 1.0
 Copyright: 2024 Meena Gopalakrishnan
*/


/*
DOCUMENTATION

Program Purpose:
    - This program generates a multiplication table up to 12x12 and prints it neatly formatted.

Compile: g++ -o Assignment1Question1  Assignment1Question1.cpp

Execution: ./Assignment1Question1 

Notes: 
    - The program uses two functions: `digs` to calculate the number of digits in a number and `mult` to generate the multiplication table for a given number.
    - Multiplication table is generated up to 12x12.
    - The program prints the multiplication table with proper formatting to align the numbers.
    - The function `digs` is used to ensure proper alignment of the numbers in the table.
    - The program terminates after printing the multiplication table.

Classes: 
    - None

Functions:
    - int digs(int product)
      Purpose: Calculates the number of digits in a given number.
      Parameters:
          - product: int - The number for which the digits need to be calculated.
      Returns:
          - int: The number of digits in the given number.

    - void mult(int n)
      Purpose: Generates the multiplication table for a given number and prints it.
      Parameters:
          - n: int - The number for which the multiplication table needs to be generated.

Variables:
    - n: int
      Purpose: Used as a loop variable to iterate through numbers from 0 to 12 to generate the multiplication table.
      
    - i: int
      Purpose: Used as a loop variable to iterate through multiplicands from 1 to 12 for each number in the multiplication table.
      
    - product: int
      Purpose: Stores the product of the multiplication operation.
      
    - j: int
      Purpose: Stores the number of digits in the product, used for formatting the output.
*/

/*
TEST PLAN

Normal Case: 
    No user input required.
    > Expected Output:
        - A multiplication table from 1 to 12 for each number from 0 to 12 is displayed.
        - Each row of the table contains the multiplication of the number (0 to 12) with numbers from 1 to 12.

    |   1 |   2 |   3 |   4 |   5 |   6 |   7 |   8 |   9 |  10 |  11 |  12 |
  1 |   1 |   2 |   3 |   4 |   5 |   6 |   7 |   8 |   9 |  10 |  11 |  12 |
  2 |   2 |   4 |   6 |   8 |  10 |  12 |  14 |  16 |  18 |  20 |  22 |  24 |
  3 |   3 |   6 |   9 |  12 |  15 |  18 |  21 |  24 |  27 |  30 |  33 |  36 |
  4 |   4 |   8 |  12 |  16 |  20 |  24 |  28 |  32 |  36 |  40 |  44 |  48 |
  5 |   5 |  10 |  15 |  20 |  25 |  30 |  35 |  40 |  45 |  50 |  55 |  60 |
  6 |   6 |  12 |  18 |  24 |  30 |  36 |  42 |  48 |  54 |  60 |  66 |  72 |
  7 |   7 |  14 |  21 |  28 |  35 |  42 |  49 |  56 |  63 |  70 |  77 |  84 |
  8 |   8 |  16 |  24 |  32 |  40 |  48 |  56 |  64 |  72 |  80 |  88 |  96 |
  9 |   9 |  18 |  27 |  36 |  45 |  54 |  63 |  72 |  81 |  90 |  99 | 108 |
 10 |  10 |  20 |  30 |  40 |  50 |  60 |  70 |  80 |  90 | 100 | 110 | 120 |
 11 |  11 |  22 |  33 |  44 |  55 |  66 |  77 |  88 |  99 | 110 | 121 | 132 |
 12 |  12 |  24 |  36 |  48 |  60 |  72 |  84 |  96 | 108 | 120 | 132 | 144 |

Bad Data Case: No inputs required.

Discussion:
    - The program generates multiplication tables from 1 to 12 for each number from 0 to 12.
    - The output is formatted to align properly for better readability.
    - The program doesn't perform extensive input validation as it doesn't rely on user input.
*/

#include <iostream>
using namespace std;

// Function to calculate the number of digits in a number
int digs(int product) {
    int j = 0;
    while (product != 0) {
        product = product / 10;
        j++;
    }
    return j;
}

// Function to generate multiplication table for a given number
void mult(int n) {
    int i = 1;
    while (i < 13) {
        int product = n * i;
        // Check the number of digits in the product to format output accordingly
        if (digs(product) == 3) {
            cout << " " << product << " |";
        } else if (digs(product) == 2) {
            cout << "  " << product << " |";
        } else {
            cout << "   " << product << " |";
        }
        i++;
    }
    cout << endl;
}

int main() {
    int n = 0;
    // Loop through numbers from 0 to 12 to create the multiplication table
    while (n < 13) {
        if (n == 0) {
            // Print the header for the multiplication table
            cout << "  " << "  |";
            mult(1); // Call the function to print the multiplication table for 1
        } else {
            // Print the number n as a column header
            if (digs(n) == 2) {
                cout << " " << n << " |";
            } else {
                cout << "  " << n << " |";
            }
            mult(n); // Call the function to print the multiplication table for n
        }
        n++;
    }
    return 0;
}
