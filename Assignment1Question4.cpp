// Assignment1Question4.cpp

/*
 Title: Assignment1Question4.cpp
 Description: Help menu that allows for selection of term's list number, and then displays the selected term's definition.
 Date: March 22, 2024
 Author: Meena Gopalakrishnan
 Version: 1.0
 Copyright: 2024 Meena Gopalakrishnan
*/


/*
 DOCUMENTATION
 
 Program Purpose:
    - Simple C++ help menu, providing information on various control flow constructs such as if, switch, for, while, and do-while loops.
 	- Demonstrate proper understanding of basic looping structure and switch statements.

 Compile (assuming Cygwin is running): g++ -o Assignment1Question4 Assignment1Question4.cpp
 Execution (assuming Cygwin is running): ./Assignment1Question4 or ./Assignment1Question4.exe
 
 Notes:     
    - Select menu item by entering the list number of selected term. 
    - Terminate the program by entering 'x' at the prompt.

 
 Classes: 
    - none

 Variables:
    - x: string
      Purpose: Used to store user input for menu selection

*/

/*
 TEST PLAN
 

Normal case (input is within range of expected values):
    > Select Help on:
        1. If
        2. Switch
        3. For
        4. While
        5. Do-while
        x. Exit
    > Selection: 1
    - Expected Output: Information about the 'if' statement is displayed:

        If: the 'if' statement is a conditional construct used to control the flow of execution based on 
        whether a specified condition evaluates to true or false. If the condition is true, the associated 
        block of code is executed; otherwise, it is bypassed or an alternative block is executed. The 'if' 
        statement can also be extended with 'else if' and 'else' clauses to handle multiple conditions sequentially. 
        This allows for more complex decision-making processes where different actions are taken based on various possible outcomes.


Bad Data case (input is outside the valid range of choices):
    > Select Help on:
        1. If
        2. Switch
        3. For
        4. While
        5. Do-while
        x. Exit
    > Selection: 6
    - Expected Output: 

        "Invalid selection. Please try again." 
 
 Discussion:
 	- The program anticipates receiving a number representing the selected menu option as a string input.
    - Input validation primarily focuses on checking if the input corresponds to a valid menu option (string comparison).
 	- Unexpected inputs such as negative numbers, words, etc, are handled in the same manner, where an error is shown, and inputs are requested again.
*/


#include <iostream>
using namespace std;

int main() {

    string x; // Variable to store user input

    // Loop to display help menu until user chooses to exit
    while (x != "x") {
        
        // Display the help menu options
        cout << "C++ Help Menu \nSelect Help on:\n1. If\n2. Switch\n3. For\n4. While\n5. Do-while\nx. Exit\n";

        // Prompt user for selection
        cout << "\nSelection: ";
        cin >> x; // Read user input

        // Switch statement to display help information based on user input
        switch (x[0]) {
            case '1':
                // Display information about the 'if' statement
                cout << "\nIf: the 'if' statement is a conditional construct used to control the flow of execution based on whether a specified condition evaluates to true or false. If the condition is true, the associated block of code is executed; otherwise, it is bypassed or an alternative block is executed. The 'if' statement can also be extended with 'else if' and 'else' clauses to handle multiple conditions sequentially. This allows for more complex decision-making processes where different actions are taken based on various possible outcomes. \n\n";
                break;
            case '2':
                // Display information about the 'switch' statement
                cout << "\nSwitch: A 'switch' statement is a branching mechanism that selects one of several code blocks to execute based on the value of a given expression. It offers a concise and efficient alternative to lengthy chains of 'if-else' statements, enhancing code readability and maintainability by grouping related conditions together. Within a 'switch' statement, each 'case' represents a specific value that the expression being evaluated may take. The 'break' keyword is used to exit the switch block after executing a matching case, preventing the execution of subsequent cases. 'Switch' statements are particularly useful when there are many possible conditions to check against a single variable.\n\n";
                break;
            case '3':
                // Display information about the 'for' loop
                cout << "\nFor: The 'for' loop is a versatile control flow construct used to iterate over a range of values and execute a block of code repeatedly. It typically consists of an initialization step, a condition for loop continuation, and an iteration step, making it well-suited for tasks requiring a fixed number of iterations and providing concise syntax for looping. Moreover, the 'for' loop can be used to iterate over arrays, lists, or other data structures, providing a concise syntax for traversing collections of elements.\n\n";
                break;
            case '4':
                // Display information about the 'while' loop
                cout << "\nWhile: The 'while' loop is a control flow construct that repeatedly executes a block of code as long as a specified condition remains true. It serves to automate tasks where the number of iterations is not predetermined and provides a mechanism for dynamic repetition until the condition evaluates to false. It is particularly useful when the number of iterations isn't known beforehand and the loop needs to continue until a certain condition is met.\n\n";
                break;
            case '5':
                // Display information about the 'do-while' loop
                cout << "\nDo-while: The 'do-while' loop is a control flow construct that executes a block of code at least once, and then continues to execute it based on a specified condition, ensuring the block executes at least once regardless of the initial condition's truth value. This structure is beneficial when you want to ensure that a specific task is performed before evaluating whether it needs to be repeated. The loop executes the code block repeatedly as long as the specified condition remains true.\n\n";
                break;
            case 'x':
                // Exit message
                cout << "\nThank you. Good bye.";
                break;
            default:
                // Error message for invalid selection
                cout << "\nInvalid selection. Please try again.\n";
                break;
        }
    }
}
