// Assignment3Question2.cpp

/*
 Title: Assignment3Question2.cpp
 Description: A program to read and display the contents of a text file, one line at a time, waiting for user input between lines.
 Date: May 12, 2024
 Author: Meena Gopalakrishnan
 Version: 1.0
 Copyright: 2024 Meena Gopalakrishnan
*/

/*
DOCUMENTATION

Program Purpose:
    - The program reads a specified text file line by line.
    - It displays each line one at a time, waiting for the user to press <Enter> before displaying the next line.

Compile: g++ -o Assignment3Question2 Assignment3Question2.cpp

Execution: ./Assignment3Question2

Notes:
    - The program prompts the user for the file name instead of using command-line arguments.
    - It reads the file and displays each line one by one.
    - The program waits for the user to press <Enter> before displaying the next line.

Classes:
    - TextFileReader:
        - Reads lines from a specified file.
        - Contains a function to display each line with a pause for user input between lines.

Functions:
    - TextFileReader::TextFileReader()
        Purpose: Default constructor.
        Parameters: None
        Returns: None

    - void TextFileReader::readAndDisplayFile(const std::string& filename)
        Purpose: Reads lines from the specified file and displays them one by one, waiting for user input between lines.
        Parameters:
            - filename (const std::string&): The name of the file to be read.
        Returns: None

Variables:
    - None

*/

/*
TEST PLAN

Test 1:
    - Description: Test with a file containing multiple lines of text.
    - Scenario:
        - User provides the file name "excerpt.txt" via prompt.
        - The file contains several lines of text.
    - Expected Output:
        The contents of the file "excerpt.txt" are displayed line by line, waiting for user input before displaying the next line.

Test 2:
    - Description: Test with an empty file.
    - Scenario:
        - User provides the file name "empty.txt" via prompt.
        - The file is empty and contains no lines.
    - Expected Output:
        No output is displayed as the file is empty.

Test 3:
    - Description: Test with a file that does not exist.
    - Scenario:
        - User provides the file name "nonexistent.txt" via prompt.
        - The file does not exist in the directory.
    - Expected Output:
        Error: Could not open file nonexistent.txt
*/

#include <iostream>
#include <fstream>
#include <string>

class TextFileReader {
public:
    // Default constructor
    TextFileReader() {}

    // Function to read and display the file
    void readAndDisplayFile(const std::string& filename) {
        std::ifstream infile(filename);
        if (!infile.is_open()) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return;
        }
        
        std::string line;
        while (std::getline(infile, line)) {
            std::cout << line << std::endl;
            std::cin.ignore();
        }

        infile.close();
    }
};

int main() {
    std::string filename;
    std::cout << "Enter the name of the file to read: ";
    std::getline(std::cin, filename);

    TextFileReader reader;
    reader.readAndDisplayFile(filename);

    return 0;
}
