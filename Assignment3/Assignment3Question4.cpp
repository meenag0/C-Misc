// Assignment3Question4.cpp

/*
 Title: Assignment3Question4.cpp
 Description: A program that demonstrates operations on arrays, including filling arrays with values, performing element-wise addition, and displaying the results.
 Date: May 18, 2024
 Author: Meena Gopalakrishnan
 Version: 1.0
 Copyright: 2024 Meena Gopalakrishnan
*/

/*
DOCUMENTATION

Program Purpose:
    - The program demonstrates basic operations on arrays:
        1. Filling the first array with loop counter values.
        2. Filling the second array with the square of the loop counter values.
        3. Adding corresponding elements from the first two arrays and storing the result in a third array.
        4. Displaying the contents of all three arrays.

Compile: g++ -o Assignment3Question4 Assignment3Question4.cpp

Execution: ./Assignment3Question4

Notes:
    - The program uses fixed-size arrays of size 25.
    - It formats the floating-point numbers to two decimal places for display.

Functions:
    - int main()
        Purpose: Main function that performs array operations and displays the results.
        Parameters: None
        Returns: int

Variables:
    - const int size
        Purpose: Defines the size of the arrays (25).

    - float array1[size]
        Purpose: Stores loop counter values (0 to 24).

    - float array2[size]
        Purpose: Stores the square of loop counter values (0, 1, 4, ..., 576).

    - float array3[size]
        Purpose: Stores the sum of corresponding elements from array1 and array2.

*/

/*
TEST PLAN

Test:
    - Description: Test the program's output with a standard set of arrays of size 25.
    - Scenario:
        - The first array is filled with values from 0 to 24.
        - The second array is filled with the squares of values from 0 to 24.
        - The third array is the sum of corresponding elements from the first two arrays.
    - Expected Output:
        Counter 0: 0.00 + 0.00 = 0.00
        Counter 1: 1.00 + 1.00 = 2.00
        Counter 2: 2.00 + 4.00 = 6.00
        Counter 3: 3.00 + 9.00 = 12.00
        Counter 4: 4.00 + 16.00 = 20.00
        Counter 5: 5.00 + 25.00 = 30.00
        Counter 6: 6.00 + 36.00 = 42.00
        Counter 7: 7.00 + 49.00 = 56.00
        Counter 8: 8.00 + 64.00 = 72.00
        Counter 9: 9.00 + 81.00 = 90.00
        Counter 10: 10.00 + 100.00 = 110.00
        Counter 11: 11.00 + 121.00 = 132.00
        Counter 12: 12.00 + 144.00 = 156.00
        Counter 13: 13.00 + 169.00 = 182.00
        Counter 14: 14.00 + 196.00 = 210.00
        Counter 15: 15.00 + 225.00 = 240.00
        Counter 16: 16.00 + 256.00 = 272.00
        Counter 17: 17.00 + 289.00 = 306.00
        Counter 18: 18.00 + 324.00 = 342.00
        Counter 19: 19.00 + 361.00 = 380.00
        Counter 20: 20.00 + 400.00 = 420.00
        Counter 21: 21.00 + 441.00 = 462.00
        Counter 22: 22.00 + 484.00 = 506.00
        Counter 23: 23.00 + 529.00 = 552.00
        Counter 24: 24.00 + 576.00 = 600.00


*/

#include <iostream>
#include <iomanip>

int main() {
    const int size = 25;
    float array1[size];
    float array2[size];
    float array3[size];

    // Fill the first array with the loop counter value
    for (int i = 0; i < size; ++i) {
        array1[i] = static_cast<float>(i);
    }

    // Fill the second array with the loop counter value squared
    for (int i = 0; i < size; ++i) {
        array2[i] = static_cast<float>(i * i);
    }

    // Add corresponding elements in the first two arrays and put the result in the third array
    for (int i = 0; i < size; ++i) {
        array3[i] = array1[i] + array2[i];
    }

    // Display all three arrays
    std::cout << std::fixed << std::setprecision(2); // Format the floating point numbers
    for (int i = 0; i < size; ++i) {
        std::cout << "Counter " << i << ": " << array1[i] << " + " << array2[i] << " = " << array3[i] << std::endl;
    }

    return 0;
}
