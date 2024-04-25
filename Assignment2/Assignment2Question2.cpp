// Assignment2Question2.cpp

/*
 Title: Assignment2Question2.cpp
 Description: A program that defines a Book class with private attributes such as title, author, publisher, ISBN, year, and edition, with public getter and setter methods implemented to access and modify these attributes
 Date: April 22, 2024
 Author: Meena Gopalakrishnan
 Version: 1.0
 Copyright: 2024 Meena Gopalakrishnan
*/

/*
DOCUMENTATION

Program Purpose:
    - This program defines a Book class to store information about books and provides methods to access and modify this information.

Compile: 
    g++ -o Assignment2Question2 Assignment2Question2.cpp

Execution: 
    ./Assignment2Question2


Notes:
    - This program defines a Book class with attributes such as title, author, publisher, ISBN, year, and edition.
    - It provides methods to retrieve and update book information.
    - The program tests the Book class by creating several books and displaying their attributes.

Classes:
    - Book:
        - Represents a book in the library.

Functions:
    - Book(const string& title, const string& author, const string& publisher, long long isbn, int year, double edition):
        - Purpose: Constructor to initialize a Book object with the given attributes.
        - Parameters:
            - title (const string&): The title of the book.
            - author (const string&): The author of the book.
            - publisher (const string&): The publisher of the book.
            - isbn (long long): The ISBN of the book.
            - year (int): The year of publication of the book.
            - edition (double): The edition of the book.

    - string getTitle() const:
        - Purpose: Getter method to retrieve the title of the book.
        - Returns:
            - string: The title of the book.

    - string getAuthor() const:
        - Purpose: Getter method to retrieve the author of the book.
        - Returns:
            - string: The author of the book.

    - string getPublisher() const:
        - Purpose: Getter method to retrieve the publisher of the book.
        - Returns:
            - string: The publisher of the book.

    - long long getISBN() const:
        - Purpose: Getter method to retrieve the ISBN of the book.
        - Returns:
            - long long: The ISBN of the book.

    - int getYear() const:
        - Purpose: Getter method to retrieve the year of publication of the book.
        - Returns:
            - int: The year of publication of the book.

    - double getEdition() const:
        - Purpose: Getter method to retrieve the edition of the book.
        - Returns:
            - double: The edition of the book.

    - void setTitle(const string& newTitle):
        - Purpose: Setter method to update the title of the book.
        - Parameters:
            - newTitle (const string&): The new title of the book.

    - void setAuthor(const string& newAuthor):
        - Purpose: Setter method to update the author of the book.
        - Parameters:
            - newAuthor (const string&): The new author of the book.

    - void setPublisher(const string& newPublisher):
        - Purpose: Setter method to update the publisher of the book.
        - Parameters:
            - newPublisher (const string&): The new publisher of the book.

    - void setISBN(long long newISBN):
        - Purpose: Setter method to update the ISBN of the book.
        - Parameters:
            - newISBN (long long): The new ISBN of the book.

    - void setYear(int newYear):
        - Purpose: Setter method to update the year of publication of the book.
        - Parameters:
            - newYear (int): The new year of publication of the book.

    - void setEdition(double newEdition):
        - Purpose: Setter method to update the edition of the book.
        - Parameters:
            - newEdition (double): The new edition of the book.

Variables:
    - title (string):
        - Purpose: Stores the title of the book.
    - author (string):
        - Purpose: Stores the author of the book.
    - publisher (string):
        - Purpose: Stores the publisher of the book.
    - isbn (long long):
        - Purpose: Stores the ISBN of the book.
    - year (int):
        - Purpose: Stores the year of publication of the book.
    - edition (double):
        - Purpose: Stores the edition of the book.
*/

/*
TEST PLAN
    Normal Case:
        - The program creates several Book objects with different attributes.
        - The program retrieves and displays the attributes of each book.
        > Expected Output:
            - Information of each book is displayed correctly:

            Title: The Great Gatsby
            Author: F. Scott Fitzgerald
            Publisher: Scribner
            ISBN: 9780743273565
            Year: 1925
            Edition: 1

            Title: To Kill a Mockingbird
            Author: Harper Lee
            Publisher: J.B. Lippincott & Co.
            ISBN: 9780061120084
            Year: 1960
            Edition: 1

            Title: 1984
            Author: George Orwell
            Publisher: Secker & Warburg
            ISBN: 9780451524935
            Year: 1949
            Edition: 1


    Bad Data Case: 
        - No input required.
        > Expected Output:
            - No user input required.
            
Discussion:
    - The program effectively manages book information using the Book class.
    - Getter and setter methods ensure the encapsulation of book attributes.
    - The program is tested with both normal and bad data cases to ensure correct functionality.
*/


#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    string title, author, publisher;
    long long isbn;
    int year;
    double edition;

public:
    // Constructor to initialize Book object with given attributes
    Book(const string& title, const string& author, const string& publisher, long long isbn, int year, double edition)
        : title(title), author(author), publisher(publisher), isbn(isbn), year(year), edition(edition) {}

    // Getter methods to retrieve book attributes
    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string getPublisher() const {
        return publisher;
    }

    long long getISBN() const {
        return isbn;
    }

    int getYear() const {
        return year;
    }

    double getEdition() const {
        return edition;
    }

    // Setter methods to update book attributes
    void setTitle(const string& newTitle) {
        title = newTitle;
    }

    void setAuthor(const string& newAuthor) {
        author = newAuthor;
    }

    void setPublisher(const string& newPublisher) {
        publisher = newPublisher;
    }

    void setISBN(long long newISBN) {
        isbn = newISBN;
    }

    void setYear(int newYear) {
        year = newYear;
    }

    void setEdition(double newEdition) {
        edition = newEdition;
    }
};

int main() {
    vector<Book> library;

    // Add some books to the library
    library.push_back(Book("The Great Gatsby", "F. Scott Fitzgerald", "Scribner", 9780743273565, 1925, 1.0));
    library.push_back(Book("To Kill a Mockingbird", "Harper Lee", "J.B. Lippincott & Co.", 9780061120084, 1960, 2.0));
    library.push_back(Book("1984", "George Orwell", "Secker & Warburg", 9780451524935, 1949, 1.0));

    // Display information of all books in the library
    for (const Book& book : library) {
        cout << "Title: " << book.getTitle() << endl;
        cout << "Author: " << book.getAuthor() << endl;
        cout << "Publisher: " << book.getPublisher() << endl;
        cout << "ISBN: " << book.getISBN() << endl;
        cout << "Year: " << book.getYear() << endl;
        cout << "Edition: " << book.getEdition() << endl;
        cout << endl;
    }

    return 0;
}