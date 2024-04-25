// Assignment2Question1.cpp

/*
 Title: Assignment2Question1.cpp
 Description: A program to create different animal objects and call their sound methods.
 Date: April 19, 2024
 Author: Meena Gopalakrishnan
 Version: 1.0
 Copyright: 2024 Meena Gopalakrishnan
*/


/*
DOCUMENTATION

Program Purpose:
    - This program demonstrates the use of inheritance and polymorphism by creating different animal objects and calling their sound methods.

Compile: 
    g++ -o Assignment2Question1 Assignment2Question1.cpp

Execution: 
    ./Assignment2Question1

Notes:
    - This program allows users to explore different animal sounds.
    - Users can select from a predefined list of animals (pig, sheep, duck, cow).
    - Based on the user's selection, the program creates an animal object and plays the corresponding sound effect (e.g., "oink" for pig, "moo" for cow).
    - The program ensures valid user input and provides informative messages throughout the interaction.

Classes:
    - Animal: 
        - Base class for different animals.
        - Contains a virtual function sound(), which is overridden by child classes.

    - Pig: 
        - Child class of Animal. 
        - Implements the sound() method to produce a pig's sound, "oink".

    - Sheep: 
        - Child class of Animal. 
        - Implements the sound() method to produce a sheep's sound, "baa".

    - Duck: 
        - Child class of Animal. 
        - Implements the sound() method to produce a duck's sound, "quack".

    - Cow: 
        - Child class of Animal. 
        - Implements the sound() method to produce a cow's sound, "moo".

    - AnimalTest: 
        - Class to test animal sound.

Functions:
    - Animal::sound(): 
        - Virtual function to produce animal sound. 
        - Overridden by child classes.

    - AnimalTest():
        - Constructor of AnimalTest class. 
        - Prompts the user to enter an animal type and calls createAnimal method.

    - AnimalTest::createAnimal(const std::string& type):
        - Function to create animal objects based on user input.
        - Parameters:
            - type: string - The type of animal to be created.
        - Returns:
            - Animal*: Pointer to the created animal object. If the type is invalid, returns nullptr.

Variables:
    None
*/


/*
TEST PLAN

Normal case:
    - Enter animal type (pig, sheep, duck, cow): pig
    - Expected Output:
        I am a pig.
        oink

Bad Data case (Invalid animal type):
    - Enter animal type (pig, sheep, duck, cow): cat
    - Expected Output: 
        Invalid animal type.

Discussion:
    - This program creates different animal objects based on user input and calls their sound methods.
    - User input is validated to ensure that only valid animal types are accepted.
*/


#include <iostream>
using namespace std;

// Base class Animal
class Animal {
public:
    // Constructor
    Animal() {
        std::cout << "I am an animal." << std::endl;
    }

    // Virtual function to produce animal sound
    virtual void sound() {
        std::cout << "An animal makes a sound based on the animal that it is." << std::endl;
    }
};

// Child class Pig
class Pig : public Animal {
public:
    // Constructor
    Pig() {
        std::cout << "I am a pig." << std::endl;
    }

    // Override sound method to produce pig sound
    void sound() override {
        std::cout << "oink" << std::endl;
    }
};

// Child class Sheep
class Sheep : public Animal {
public:
    // Constructor
    Sheep() {
        std::cout << "I am a sheep." << std::endl;
    }

    // Override sound method to produce sheep sound
    void sound() override {
        std::cout << "baah" << std::endl;
    }
};

// Child class Duck
class Duck : public Animal {
public:
    // Constructor
    Duck() {
        std::cout << "I am a duck." << std::endl;
    }

    // Override sound method to produce duck sound
    void sound() override {
        std::cout << "quack" << std::endl;
    }
};

// Child class Cow
class Cow : public Animal {
public:
    // Constructor
    Cow() {
        std::cout << "I am a cow." << std::endl;
    }

    // Override sound method to produce cow sound
    void sound() override {
        std::cout << "moo" << std::endl;
    }
};

// Class AnimalTest to test animal sound
class AnimalTest {
public:
    // Constructor
    AnimalTest(const std::string& type) {
        // Create animal object based on user input
        Animal* animal = createAnimal(type);
        // If animal object created successfully, call its sound method
        if (animal) {
            animal->sound();
        } else {
            // If animal object creation failed, print error message
            std::cout << "Invalid animal type." << std::endl;
        }
    }

private:
    // Function to create animal objects based on user input
    Animal* createAnimal(const std::string& type) {
        // Convert input to lowercase
        std::string lowercaseType = type;
        for (char& c : lowercaseType) {
            c = tolower(c);
        }

        // Create animal object based on input
        if (lowercaseType == "pig") {
            return new Pig;
        } else if (lowercaseType == "sheep") {
            return new Sheep;
        } else if (lowercaseType == "duck") {
            return new Duck;
        } else if (lowercaseType == "cow") {
            return new Cow;
        } else {
            // If input is not valid, return nullptr
            return nullptr;
        }
    }
};

int main() {
    std::string animalType;

    // Main function to create instances of each animal based on user input
    while (true) {
        // Prompt user to enter animal type
        std::cout << "Enter animal type (pig, sheep, duck, cow) or type 'quit' to exit: ";
        std::cin >> animalType;

        // Exit loop if user enters 'quit'
        if (animalType == "quit") {
            break;
        }

        // Create AnimalTest object for the entered animal type
        AnimalTest animalTest(animalType);
    }

    return 0;
}