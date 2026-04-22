#pragma once
#include <string>

class Book {
    std::string title;
    std::string author;
    int bookId;
    bool isAvailable;
    static int uniqueBookId;

public:
    friend class Transaction;
    Book();
    Book(std::string t, std::string a);
    int getBookId() const;
    void setAvailability(bool status);
    bool isBookAvailable() const;
    std::string getBookTitle();
    std::string getBookAuthor() const;
};