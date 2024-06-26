// Assignment3Question1.cpp

/*
 Title: Assignment3Question1.cpp
 Description: A program to count whitespace-separated words in a given file.
 Date: May 12, 2024
 Author: Meena Gopalakrishnan
 Version: 1.0
 Copyright: 2024 Meena Gopalakrishnan
*/

/*
DOCUMENTATION

Program Purpose:
    - The program counts the number of whitespace-separated words in a specified file.

Compile: g++ -o Assignment3Question1 Assignment3Question1.cpp

Execution: ./Assignment3Question1

Notes:
    - Program prompts the user to enter the file name.
    - The program reads the file and counts the number of whitespace-separated words.
    - It outputs the total word count to the console.

Functions:
    - int countWordsInFile(const std::string& filename)
        Purpose: Counts the number of whitespace-separated words in the specified file.
        Parameters:
            - filename (const std::string&): The name of the file to be processed.
        Returns:
            - int: The count of words in the file or -1 if the file could not be opened.

Variables:
    - std::string word
        Purpose: Temporarily stores each word read from the file.

    - int wordCount
        Purpose: Stores the count of words read from the file.

    - std::string filename
        Purpose: Stores the name of the file entered by the user.

*/


/*
TEST PLAN

Test 1:
    - Description: Test with a file containing multiple lines of text.
    - Scenario:
        - User enters the file name "excerpt.txt".
        - The file contains several lines of text with multiple words.
    - Expected Output:
        The file excerpt.txt contains <wordCount> words.

Test 2:
    - Description: Test with an empty file.
    - Scenario:
        - User enters the file name "empty.txt".
        - The file is empty and contains no words.
    - Expected Output:
        The file empty.txt contains 0 words.

Test 3:
    - Description: Test with a file that does not exist.
    - Scenario:
        - User enters the file name "nonexistent.txt".
        - The file does not exist in the directory.
    - Expected Output:
        Error: Could not open file nonexistent.txt
*/



#include <iostream>
#include <fstream>
#include <string>

// Function to count whitespace-separated words in a file
int countWordsInFile(const std::string& filename) {
    std::ifstream infile(filename.c_str()); // Open the file
    if (!infile.good()) { // Check if the file is open
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return -1; // Return -1 if the file could not be opened
    }

    std::string word;
    int wordCount = 0;

    // Read words from the file and count them
    while (infile >> word) {
        wordCount++;
    }

    infile.close(); // Close the file
    return wordCount; // Return the word count
}

int main() {
    std::string filename;

    // Prmpt the user to input the filename
    std::cout << "Enter the name of the file: ";
    std::getline(std::cin, filename);

    // Count the words in the file
    int wordCount = countWordsInFile(filename);

    // Check if the word count is valid
    if (wordCount != -1) {
        std::cout << "The file " << filename << " contains " << wordCount << " words." << std::endl;
    }

    return 0;
}
