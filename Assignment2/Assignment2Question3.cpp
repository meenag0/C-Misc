
// Assignment2Question3.cpp

/*
 Title: Assignment2Question3.cpp
 Description: A program to simulate an elevator moving between floors.
 Date: April 18, 2024
 Author: Meena Gopalakrishnan
 Version: 1.0
 Copyright: 2024 Meena Gopalakrishnan
*/

/*
DOCUMENTATION

Program Purpose:
    - The program simulates an elevator moving between floors in a building.

Compile: g++ -o Assignment2Question3  Assignment2Question3.cpp

Execution: ./Assignment2Question3

Notes:
    - Program uses the Elevator class to represent the elevator.
    - The Elevator class has attributes currentFloor and totalFloors, and methods moveToFloor, finalize, and getCurrentFloor 
      to simulate elevator operations.
    - The program tests the Elevator class by simulating various scenarios of the elevator moving between floors.

Classes:
    - Elevator:
        - Represents an elevator in a building.
        - Contains functions to move the elevator between floors and return it to the first floor.

Functions:
    - int Elevator::getCurrentFloor() const
        Purpose: Returns the current floor of the elevator.
        Parameters: None
        Returns:
            - int: The current floor of the elevator.

    - void Elevator::moveToFloor(int floor)
        Purpose: Moves the elevator to the specified floor.
        Parameters:
            - floor (int): The floor to which the elevator needs to be moved.
        Returns: None

    - void Elevator::finalize()
        Purpose: Returns the elevator to the first floor.
        Parameters: None
        Returns: None

    - void testElevator(Elevator elevator, const string &testName, int floor1, int floor2)
        Purpose: Function to test the Elevator class.
        Parameters:
            - elevator (Elevator): The elevator object to be tested.
            - testName (const string&): The name of the test.
            - floor1 (int): The floor to move the elevator to initially.
            - floor2 (int): The floor to move the elevator to next.
        Returns: None

Variables:
    - int currentFloor
        Purpose: Represents the current floor of the elevator.

    - int totalFloors
        Purpose: Represents the total number of floors in the building.
*/

/*
TEST PLAN

Test 1:
    - Description: Test with default 5-storey building
    - Scenario:
        - Elevator starts at the first floor.
        - Moves from floor 1 to floor 3.
        - Moves from floor 3 to floor 5.
        - Elevator returns to the first floor.
    - Expected Output:
        Current floor: 1
        Moving from floor 1 to floor 3
        Current floor: 3
        Moving from floor 3 to floor 5
        Current floor: 5
        Elevator ending: elevator returned to the first floor

Test 2:
    - Description: Test with a 10-storey building
    - Scenario:
        - Elevator starts at the first floor.
        - Moves from floor 1 to floor 7.
        - Moves from floor 7 to floor 10.
        - Elevator returns to the first floor.
    - Expected Output:
        Current floor: 1
        Moving from floor 1 to floor 7
        Current floor: 7
        Moving from floor 7 to floor 10
        Current floor: 10
        Elevator ending: elevator returned to the first floor

Test 3:
    - Description: Test with an 8-storey building
    - Scenario:
        - Elevator starts at the first floor.
        - Moves from floor 1 to floor 2.
        - Moves from floor 2 to floor 8.
        - Elevator returns to the first floor.
    - Expected Output:
        Current floor: 1
        Moving from floor 1 to floor 2
        Current floor: 2
        Moving from floor 2 to floor 8
        Current floor: 8
        Elevator ending: elevator returned to the first floor

Test 4:
    - Description: Test with a 12-storey building
    - Scenario:
        - Elevator starts at the first floor.
        - Moves from floor 1 to floor 6.
        - Moves from floor 6 to floor 12.
        - Elevator returns to the first floor.
    - Expected Output:
        Current floor: 1
        Moving from floor 1 to floor 6
        Current floor: 6
        Moving from floor 6 to floor 12
        Current floor: 12
        Elevator ending: elevator returned to the first floor
*/

#include <iostream>
using namespace std;

class Elevator {
private:
    int currentFloor;
    int totalFloors;

public:
    // Constructor with default 5 floors
    Elevator() {
        totalFloors = 5;
        currentFloor = 1;
    }

    // Constructor with custom number of floors
    Elevator(int n) {
        totalFloors = n;
        currentFloor = 1;
    }

    // Moves the elevator to the specified floor
    void moveToFloor(int n) {
        if (n >= 1 && n <= totalFloors) {
            cout << "Moving from floor " << currentFloor << " to floor " << n << endl;
            currentFloor = n;
        } else {
            cout << "Invalid floor!" << endl;
        }
    }

    // Resets the elevator to the first floor
    void finalize() {
        cout << "Elevator ending: elevator returned to the first floor \n" << endl;
        currentFloor = 1;
    }

    // Getter method to retrieve the current floor of the elevator
    int getCurrentFloor() const {
        return currentFloor;
    }

    // Termination: Instance is set to null
    ~Elevator() {
    }
};

// Tests the elevator by moving it to different floors and displaying the current floor
void testElevator(Elevator elevator, const string &testName, int floor1, int floor2) {
    cout << testName << ":" << endl;
    cout << "Current floor: " << elevator.getCurrentFloor() << endl;
    elevator.moveToFloor(floor1);
    cout << "Current floor: " << elevator.getCurrentFloor() << endl;
    elevator.moveToFloor(floor2);
    cout << "Current floor: " << elevator.getCurrentFloor() << endl;
    cout << endl;
    elevator.finalize();
}

int main() {
    // Test scenarios
    Elevator elevator1; // Default 5-storey building
    testElevator(elevator1, "Test 1", 3, 5);

    Elevator elevator2(10); // 10-storey building
    testElevator(elevator2, "Test 2", 7, 10);

    Elevator elevator3(8); // 8-storey building
    testElevator(elevator3, "Test 3", 2, 8);

    Elevator elevator4(12); // 12-storey building
    testElevator(elevator4, "Test 4", 6, 12);

    Elevator elevator5(15); // 15-storey building
    testElevator(elevator5, "Test 5", 9, 15);

    return 0;
}