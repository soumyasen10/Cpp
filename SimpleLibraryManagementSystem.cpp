#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Book {
private:
    std::string title;
    std::string author;
    int publicationYear;

public:
 
    Book(const std::string& bookTitle, const std::string& bookAuthor, int year)
        : title(bookTitle), author(bookAuthor), publicationYear(year) {}

  
    void display() const {
        std::cout << "Title: " << title << "\n"
                  << "Author: " << author << "\n"
                  << "Publication Year: " << publicationYear << std::endl;
    }
    std::string getTitle() const {
        return title;
    }
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const std::string& title, const std::string& author, int year) {
        books.emplace_back(title, author, year);
    }

  
    void listBooks() const {
        for (const auto& book : books) {
            book.display();
            std::cout << "-------------------" << std::endl;
        }
    }

    void searchBook(const std::string& title) const {
        auto it = std::find_if(books.begin(), books.end(), 
                               [&title](const Book& book) { return book.getTitle() == title; });

        if (it != books.end()) {
            std::cout << "Book found:" << std::endl;
            it->display();
        } else {
            std::cout << "Book not found." << std::endl;
        }
    }
};

int main() {
    Library library;
    int choice;
    std::string title, author;
    int year;

    do {
        std::cout << "Library Management System" << std::endl;
        std::cout << "1. Add Book" << std::endl;
        std::cout << "2. List Books" << std::endl;
        std::cout << "3. Search Book" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();  

        switch (choice) {
            case 1:
                std::cout << "Enter book title: ";
                std::getline(std::cin, title);
                std::cout << "Enter book author: ";
                std::getline(std::cin, author);
                std::cout << "Enter publication year: ";
                std::cin >> year;
                std::cin.ignore();  
                library.addBook(title, author, year);
                break;

            case 2:
                library.listBooks();
                break;

            case 3:
                std::cout << "Enter book title to search: ";
                std::getline(std::cin, title);
                library.searchBook(title);
                break;

            case 4:
                std::cout << "Exiting program." << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
