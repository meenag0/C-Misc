
// Assignment2Question4.cpp

/*
 Title: Assignment2Question4.cpp
 Description: A program to simulate the behavior of different rodents.
 Date: March 22, 2024
 Author: Meena Gopalakrishnan
 Version: 1.0
 Copyright: 2024 Meena Gopalakrishnan
*/


/*
DOCUMENTATION

Program Purpose:
    - This program simulates the behavior of different rodents such as Mouse, Gerbil, Hamster, and Guinea Pig.

Compile: g++ -o Assignment2Question4  Assignment2Question4.cpp

Execution: ./Assignment2Question4 

Notes:
    - The program defines a base class Rodent, and derived classes Mouse, Gerbil, Hamster, and GuineaPig.
    - Each rodent class implements virtual functions to simulate eating and moving behaviors.
    - The program tests the behavior of each rodent by creating objects of each class and calling their respective functions.

Classes:
    - Rodent:
        - Base class representing a generic rodent.
        - Virtual functions: eat(), sleep(), groom(), move().

    - Mouse:
        - Derived class from Rodent representing a Mouse.
        - Overrides: eat(), move().

    - Gerbil:
        - Derived class from Rodent representing a Gerbil.
        - Overrides: eat(), move().

    - Hamster:
        - Derived class from Rodent representing a Hamster.
        - Overrides: eat(), move().

    - GuineaPig:
        - Derived class from Rodent representing a Guinea Pig.
        - Overrides: eat(), move().

Functions:
    - void Rodent::eat()
        Purpose: Simulates the eating behavior of a rodent.
        Parameters: None
        Returns: None

    - void Rodent::sleep()
        Purpose: Simulates the sleeping behavior of a rodent.
        Parameters: None
        Returns: None

    - void Rodent::groom()
        Purpose: Simulates the grooming behavior of a rodent.
        Parameters: None
        Returns: None

    - void Rodent::move()
        Purpose: Simulates the movement behavior of a rodent.
        Parameters: None
        Returns: None

    - void Mouse::eat()
        Purpose: Simulates the eating behavior of a mouse.
        Parameters: None
        Returns: None

    - void Mouse::move()
        Purpose: Simulates the movement behavior of a mouse.
        Parameters: None
        Returns: None

    - void Gerbil::eat()
        Purpose: Simulates the eating behavior of a gerbil.
        Parameters: None
        Returns: None

    - void Gerbil::move()
        Purpose: Simulates the movement behavior of a gerbil.
        Parameters: None
        Returns: None

    - void Hamster::eat()
        Purpose: Simulates the eating behavior of a hamster.
        Parameters: None
        Returns: None

    - void Hamster::move()
        Purpose: Simulates the movement behavior of a hamster.
        Parameters: None
        Returns: None

    - void GuineaPig::eat()
        Purpose: Simulates the eating behavior of a guinea pig.
        Parameters: None
        Returns: None

    - void GuineaPig::move()
        Purpose: Simulates the movement behavior of a guinea pig.
        Parameters: None
        Returns: None
*/

/*
TEST PLAN

Test 1:
    Description: Testing Mouse behavior
    Scenario:
        - Create a Mouse object.
        - Call eat, sleep, groom, and move functions.
    Expected Output:
        Mouse eating seeds
        Rodent sleeping
        Rodent grooming
        Mouse scurrying

Test 2:
    Description: Testing Gerbil behavior
    Scenario:
        - Create a Gerbil object.
        - Call eat, sleep, groom, and move functions.
    Expected Output:
        Gerbil is eating grains
        Rodent sleeping
        Rodent grooming
        Gerbil is burrowing

Test 3:
    Description: Testing Hamster behavior
    Scenario:
        - Create a Hamster object.
        - Call eat, sleep, groom, and move functions.
    Expected Output:
        Hamster is eating pellets
        Rodent sleeping
        Rodent grooming
        Hamster is running on a wheel

Test 4:
    Description: Testing GuineaPig behavior
    Scenario:
        - Create a GuineaPig object.
        - Call eat, sleep, groom, and move functions.
    Expected Output:
        Guinea Pig is eating grass
        Rodent sleeping
        Rodent grooming
        Guinea Pig is running around
*/



#include <iostream>
#include <string>
using namespace std;

// Rodent class
class Rodent {
public:
    // Virtual function to simulate eating
    virtual void eat() {
        cout << "Rodent eating" << endl;
    }

    // Virtual function to simulate sleeping
    virtual void sleep() {
        cout << "Rodent sleeping" << endl;
    }

    // Virtual function to simulate grooming
    virtual void groom() {
        cout << "Rodent grooming" << endl;
    }

    // Virtual function to simulate moving
    virtual void move() {
        cout << "Rodent moving" << endl;
    }
};

// Mouse class, derived from Rodent
class Mouse : public Rodent {
public:
    // Overrides the eat function for a Mouse
    void eat() override {
        cout << "Mouse eating seeds" << endl;
    }

    // Overrides the move function for a Mouse
    void move() override {
        cout << "Mouse scurrying" << endl;
    }
};

// Gerbil class, derived from Rodent
class Gerbil : public Rodent {
public:
    // Overrides the eat function for a Gerbil
    void eat() override {
        cout << "Gerbil is eating grains" << endl;
    }

    // Overrides the move function for a Gerbil
    void move() override {
        cout << "Gerbil is burrowing" << endl;
    }
};

// Hamster class, derived from Rodent
class Hamster : public Rodent {
public:
    // Overrides the eat function for a Hamster
    void eat() override {
        cout << "Hamster is eating pellets" << endl;
    }

    // Overrides the move function for a Hamster
    void move() override {
        cout << "Hamster is running on a wheel" << endl;
    }
};

// GuineaPig class, derived from Rodent
class GuineaPig : public Rodent {
public:
    // Overrides the eat function for a Guinea Pig
    void eat() override {
        cout << "Guinea Pig is eating grass" << endl;
    }

    // Overrides the move function for a Guinea Pig
    void move() override {
        cout << "Guinea Pig is running around" << endl;
    }
};

// Main function
int main() {
    // Creating objects for each type of Rodent
    Mouse mouse;
    Gerbil gerbil;
    Hamster hamster;
    GuineaPig guineaPig;

    // Simulating actions for each rodent
    mouse.eat();
    mouse.sleep();
    mouse.groom();
    mouse.move();

    gerbil.eat();
    gerbil.sleep();
    gerbil.groom();
    gerbil.move();

    hamster.eat();
    hamster.sleep();
    hamster.groom();
    hamster.move();

    guineaPig.eat();
    guineaPig.sleep();
    guineaPig.groom();
    guineaPig.move();

    return 0;
}