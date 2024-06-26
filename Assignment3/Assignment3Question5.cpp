// Assignment3Question5.cpp

/*
 Title: Assignment3Question5.cpp
 Description: A program to manage a collection of books, display them, and sort them by title and year of publication.
 Date: May 22, 2024
 Author: Meena Gopalakrishnan
 Version: 1.0
 Copyright: 2024 Meena Gopalakrishnan
*/

/*
DOCUMENTATION

Program Purpose:
    - The program manages a collection of books.
    - It allows for the creation of book objects with various attributes.
    - It displays the books in the order they were entered.
    - It sorts the books by title and year of publication and then displays them.

Compile: g++ -o Assignment3Question5 Assignment3Question5.cpp

Execution: ./Assignment3Question5

Notes:
    - The program uses the Book class to represent individual books.
    - It uses a comparator class (BookComparator) to sort the books by title and year.
    - The Bookshelf class contains the main method to demonstrate the functionality of the program.

Classes:
    - Book:
        - Represents a book with attributes such as title, ISBN, author, edition, publisher, and year.
        - Contains methods to get and set these attributes and to display the book details.

    - BookComparator:
        - A functor to compare two books by title and year of publication for sorting.

    - Bookshelf:
        - Contains a static main method to create, display, and sort a collection of books.

Functions:
    - Book::Book()
        Purpose: Default constructor.
        Parameters: None
        Returns: None

    - Book::Book(const std::string& title, const std::string& ISBN, const std::string& author,
                 const std::string& edition, const std::string& publisher, int year)
        Purpose: Parameterized constructor to initialize book attributes.
        Parameters:
            - title (const std::string&): Title of the book.
            - ISBN (const std::string&): ISBN of the book.
            - author (const std::string&): Author of the book.
            - edition (const std::string&): Edition of the book.
            - publisher (const std::string&): Publisher of the book.
            - year (int): Year of publication.
        Returns: None

    - std::string Book::getTitle() const
        Purpose: Gets the title of the book.
        Parameters: None
        Returns:
            - std::string: Title of the book.

    - std::string Book::getISBN() const
        Purpose: Gets the ISBN of the book.
        Parameters: None
        Returns:
            - std::string: ISBN of the book.

    - std::string Book::getAuthor() const
        Purpose: Gets the author of the book.
        Parameters: None
        Returns:
            - std::string: Author of the book.

    - std::string Book::getEdition() const
        Purpose: Gets the edition of the book.
        Parameters: None
        Returns:
            - std::string: Edition of the book.

    - std::string Book::getPublisher() const
        Purpose: Gets the publisher of the book.
        Parameters: None
        Returns:
            - std::string: Publisher of the book.

    - int Book::getYear() const
        Purpose: Gets the year of publication of the book.
        Parameters: None
        Returns:
            - int: Year of publication.

    - void Book::setTitle(const std::string& title)
        Purpose: Sets the title of the book.
        Parameters:
            - title (const std::string&): Title of the book.
        Returns: None

    - void Book::setISBN(const std::string& ISBN)
        Purpose: Sets the ISBN of the book.
        Parameters:
            - ISBN (const std::string&): ISBN of the book.
        Returns: None

    - void Book::setAuthor(const std::string& author)
        Purpose: Sets the author of the book.
        Parameters:
            - author (const std::string&): Author of the book.
        Returns: None

    - void Book::setEdition(const std::string& edition)
        Purpose: Sets the edition of the book.
        Parameters:
            - edition (const std::string&): Edition of the book.
        Returns: None

    - void Book::setPublisher(const std::string& publisher)
        Purpose: Sets the publisher of the book.
        Parameters:
            - publisher (const std::string&): Publisher of the book.
        Returns: None

    - void Book::setYear(int year)
        Purpose: Sets the year of publication of the book.
        Parameters:
            - year (int): Year of publication.
        Returns: None

    - void Book::display() const
        Purpose: Displays the details of the book.
        Parameters: None
        Returns: None

    - bool BookComparator::operator()(const Book& a, const Book& b) const
        Purpose: Compares two books by title and year of publication.
        Parameters:
            - a (const Book&): First book to compare.
            - b (const Book&): Second book to compare.
        Returns:
            - bool: True if the first book should come before the second, false otherwise.

    - static void Bookshelf::main()
        Purpose: Demonstrates the functionality of creating, displaying, and sorting books.
        Parameters: None
        Returns: None

Variables:
    - std::string title
        Purpose: Stores the title of the book.

    - std::string ISBN
        Purpose: Stores the ISBN of the book.

    - std::string author
        Purpose: Stores the author of the book.

    - std::string edition
        Purpose: Stores the edition of the book.

    - std::string publisher
        Purpose: Stores the publisher of the book.

    - int year
        Purpose: Stores the year of publication of the book.

    - std::vector<Book> books
        Purpose: Stores the collection of book objects.


Test 1:
    - Description: Test the creation and display of Book objects.
    - Scenario:
        - Create 12 Book objects with distinct attributes.
        - Store the Book objects in an ArrayList 
        - Display the attributes of all books in the order they were entered.
    - Expected Output:
        Each book's attributes (title, ISBN, author, edition, publisher, year) should be displayed in the order the books were added.

Test 2:
    - Description: Test sorting books by title and year of publication.
    - Scenario:
        - Create 12 Book objects with distinct attributes.
        - Store the Book objects in an ArrayList (std::vector in C++).
        - Sort the books by title and then by year of publication.
        - Display the sorted books.
    - Expected Output:
        Books should be displayed in alphabetical order by title.
        If two books have the same title, they should be sorted by year of publication.

*/



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Book Class Definition
class Book {
private:
    std::string title;
    std::string ISBN;
    std::string author;
    std::string edition;
    std::string publisher;
    int year;

public:
    // Default constructor
    Book() {}

    // Parameterized constructor
    Book(const std::string& title, const std::string& ISBN, const std::string& author,
         const std::string& edition, const std::string& publisher, int year) 
        : title(title), ISBN(ISBN), author(author), edition(edition), publisher(publisher), year(year) {}

    // Get methods
    std::string getTitle() const { return title; }
    std::string getISBN() const { return ISBN; }
    std::string getAuthor() const { return author; }
    std::string getEdition() const { return edition; }
    std::string getPublisher() const { return publisher; }
    int getYear() const { return year; }

    // Set methods
    void setTitle(const std::string& title) { this->title = title; }
    void setISBN(const std::string& ISBN) { this->ISBN = ISBN; }
    void setAuthor(const std::string& author) { this->author = author; }
    void setEdition(const std::string& edition) { this->edition = edition; }
    void setPublisher(const std::string& publisher) { this->publisher = publisher; }
    void setYear(int year) { this->year = year; }

    // Display method
    void display() const {
        std::cout << "Title: " << title << ", ISBN: " << ISBN << ", Author: " << author
                  << ", Edition: " << edition << ", Publisher: " << publisher
                  << ", Year: " << year << std::endl;
    }
};

// Comparator for sorting books by title and then by year of publication
class BookComparator {
public:
    bool operator()(const Book& a, const Book& b) const {
        if (a.getTitle() == b.getTitle()) {
            return a.getYear() < b.getYear();
        }
        return a.getTitle() < b.getTitle();
    }
};

// Bookshelf Class Definition
class Bookshelf {
public:
    static void main() {
        std::vector<Book> books;

        // Creating 12 Book objects with distinct attributes
        books.push_back(Book("The Great Gatsby", "ISBN001", "F. Scott Fitzgerald", "1st", "Scribner", 1925));
        books.push_back(Book("To Kill a Mockingbird", "ISBN002", "Harper Lee", "1st", "J.B. Lippincott & Co.", 1960));
        books.push_back(Book("1984", "ISBN003", "George Orwell", "1st", "Secker & Warburg", 1949));
        books.push_back(Book("Pride and Prejudice", "ISBN004", "Jane Austen", "1st", "T. Egerton", 1813));
        books.push_back(Book("The Catcher in the Rye", "ISBN005", "J.D. Salinger", "1st", "Little, Brown and Company", 1951));
        books.push_back(Book("The Hobbit", "ISBN006", "J.R.R. Tolkien", "1st", "George Allen & Unwin", 1937));
        books.push_back(Book("Moby-Dick", "ISBN007", "Herman Melville", "1st", "Harper & Brothers", 1851));
        books.push_back(Book("War and Peace", "ISBN008", "Leo Tolstoy", "1st", "The Russian Messenger", 1869));
        books.push_back(Book("The Odyssey", "ISBN009", "Homer", "1st", "Ancient Greece", -800));
        books.push_back(Book("The Divine Comedy", "ISBN010", "Dante Alighieri", "1st", "John Wiley & Sons", 1320));
        books.push_back(Book("Hamlet", "ISBN011", "William Shakespeare", "1st", "N. Ling", 1603));
        books.push_back(Book("The Iliad", "ISBN012", "Homer", "1st", "Ancient Greece", -750));

        // Displaying books in the order they were entered
        std::cout << "Books in the order they were entered:\n";
        for (size_t i = 0; i < books.size(); ++i) {
            books[i].display();
        }

        // Sorting books by title and then by year of publication
        std::sort(books.begin(), books.end(), BookComparator());

        // Displaying sorted books
        std::cout << "\nBooks sorted by title and year of publication:\n";
        for (size_t i = 0; i < books.size(); ++i) {
            books[i].display();
        }
    }
};

int main() {
    Bookshelf::main();
    return 0;
}