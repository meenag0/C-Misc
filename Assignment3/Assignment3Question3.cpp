// Assignment3Question3.cpp

/*
 Title: Assignment3Question3.cpp
 Description: A program to read and display the contents of a text file, line by line, with line numbers.
 Date: May 15, 2024
 Author: Meena Gopalakrishnan
 Version: 1.0
 Copyright: 2024 Meena Gopalakrishnan
*/

/*
DOCUMENTATION

Program Purpose:
    - The program reads up to 100 lines from a specified text file.
    - It concatenates all lines into a single string and displays the file contents.
    - It displays the lines with line numbers.

Compile: g++ -o Assignment3Question3 Assignment3Question3.cpp

Execution: ./Assignment3Question3 <filename>

Notes:
    - Program uses command-line arguments to obtain the file name.
    - The program reads the file and stores up to 100 lines in an array.
    - It provides functions to display the concatenated file contents and to display each line with line numbers.

Classes:
    - TextFileReader:
        - Reads and stores up to 100 lines from a specified file.
        - Contains functions to return the concatenated file contents and to display each line with line numbers.

    - TextFileReaderDemo:
        - Provides a static main function to demonstrate the use of the TextFileReader class.

Functions:
    - TextFileReader::TextFileReader()
        Purpose: Default constructor that initializes line count to 0.
        Parameters: None
        Returns: None

    - TextFileReader::TextFileReader(const std::string& filename)
        Purpose: Constructor that reads lines from the specified file and stores them in an array.
        Parameters:
            - filename (const std::string&): The name of the file to be read.
        Returns: None

    - std::string TextFileReader::contents() const
        Purpose: Concatenates all lines read from the file into a single string.
        Parameters: None
        Returns:
            - std::string: A string containing all lines read from the file, concatenated together.

    - void TextFileReader::display() const
        Purpose: Displays the lines read from the file with line numbers.
        Parameters: None
        Returns: None

    - static void TextFileReaderDemo::main(int argc, char* argv[])
        Purpose: Demonstrates the use of the TextFileReader class by reading a file and displaying its contents.
        Parameters: 
            - argc (int): The number of command-line arguments.
            - argv (char*[]): The array of command-line arguments.
        Returns: None

Variables:
    - std::string lines[100]
        Purpose: Array to store up to 100 lines from the file.

    - int lineCount
        Purpose: Stores the count of lines read from the file.

    - std::string line
        Purpose: Temporarily stores each line read from the file.

    - std::string filename
        Purpose: Stores the name of the file entered by the user.
*/

/*
TEST PLAN

Test 1:
    - Description: Test with a file containing multiple lines of text.
    - Scenario:
        - User enters the file name "excerpt.txt" as a command-line argument.
        - The file contains several lines of text.
    - Expected Output:
        The contents of the file "excerpt.txt" are displayed concatenated together.
        Each line is then displayed with line numbers.

Test 2:
    - Description: Test with an empty file.
    - Scenario:
        - User enters the file name "empty.txt" as a command-line argument.
        - The file is empty and contains no lines.
    - Expected Output:
        No contents are displayed as the file is empty.
        No lines are displayed with line numbers.

Test 3:
    - Description: Test with a file that does not exist.
    - Scenario:
        - User enters the file name "nonexistent.txt" as a command-line argument.
        - The file does not exist in the directory.
    - Expected Output:
        Error: Could not open file nonexistent.txt
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class TextFileReader {
private:
    std::string lines[100];  // Array to store up to 100 lines from the file
    int lineCount;           // Number of lines read from the file

public:
    // Default constructor
    TextFileReader() : lineCount(0) {}

    // Constructor that takes a filename
    TextFileReader(const std::string& filename) : lineCount(0) {
        std::ifstream infile(filename);
        if (!infile.is_open()) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return;
        }

        std::string line;
        while (lineCount < 100 && std::getline(infile, line)) {
            lines[lineCount++] = line;
        }

        infile.close();
    }

    // Function to concatenate all lines into a single string
    std::string contents() const {
        std::ostringstream oss;
        for (int i = 0; i < lineCount; ++i) {
            oss << lines[i] << "\n";
        }
        return oss.str();
    }

    // Function to display the lines with line numbers
    void display() const {
        for (int i = 0; i < lineCount; ++i) {
            std::cout << "Line " << (i + 1) << ": " << lines[i] << std::endl;
        }
    }
};

class TextFileReaderDemo {
public:
    static void main(int argc, char* argv[]) {
        if (argc < 2) {
            std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
            return;
        }

        std::string filename = argv[1];
        TextFileReader reader(filename);

        std::cout << "\nFile Contents:\n";
        std::cout << reader.contents();

        std::cout << "\nDisplaying file contents with line numbers:\n";
        reader.display();
    }
};

int main(int argc, char* argv[]) {
    TextFileReaderDemo::main(argc, argv);
    return 0;
}
