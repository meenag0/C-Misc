#include <iostream>
using namespace std;

int main() {

    string x;

    while (x != "x") {

        cout << "C++ Help Menu \nSelect Help on:\n1. If\n2. Switch\n3. For\n4. While\n5. Do-while\nx. Exit\n";

        cout << "\nSelection: ";
        cin >> x;

        switch (x[0]) {
            case '1':
                cout << "\nIf: the 'if' statement is a conditional construct used to control the flow of execution based on whether a specified condition evaluates to true or false. If the condition is true, the associated block of code is executed; otherwise, it is bypassed or an alternative block is executed. The 'if' statement can also be extended with 'else if' and 'else' clauses to handle multiple conditions sequentially. This allows for more complex decision-making processes where different actions are taken based on various possible outcomes. \n\n";
                break;
            case '2':
                cout << "\nSwitch: A 'switch' statement is a branching mechanism that selects one of several code blocks to execute based on the value of a given expression. It offers a concise and efficient alternative to lengthy chains of 'if-else' statements, enhancing code readability and maintainability by grouping related conditions together. Within a 'switch' statement, each 'case' represents a specific value that the expression being evaluated may take. The 'break' keyword is used to exit the switch block after executing a matching case, preventing the execution of subsequent cases. 'Switch' statements are particularly useful when there are many possible conditions to check against a single variable.\n\n";
                break;
            case '3':
                cout << "\nFor: The 'for' loop is a versatile control flow construct used to iterate over a range of values and execute a block of code repeatedly. It typically consists of an initialization step, a condition for loop continuation, and an iteration step, making it well-suited for tasks requiring a fixed number of iterations and providing concise syntax for looping. Moreover, the 'for' loop can be used to iterate over arrays, lists, or other data structures, providing a concise syntax for traversing collections of elements.\n\n";
                break;
            case '4':
                cout << "\nWhile: The 'while' loop is a control flow construct that repeatedly executes a block of code as long as a specified condition remains true. It serves to automate tasks where the number of iterations is not predetermined and provides a mechanism for dynamic repetition until the condition evaluates to false. It is particularly useful when the number of iterations isn't known beforehand and the loop needs to continue until a certain condition is met.\n\n";
                break;
            case '5':
                cout << "\nDo-while: The 'do-while' loop is a control flow construct that executes a block of code at least once, and then continues to execute it based on a specified condition, ensuring the block executes at least once regardless of the initial condition's truth value. This structure is beneficial when you want to ensure that a specific task is performed before evaluating whether it needs to be repeated. The loop executes the code block repeatedly as long as the specified condition remains true.\n\n";
                break;
            case 'x':
                cout << "\nThank you. Good bye.";
                break;
            default:
                cout << "\nInvalid selection. Please try again.\n";
                break;
        }
    }
}