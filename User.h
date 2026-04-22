#pragma once
#include <string>
#include "Book.h"

class User {
    std::string name;
    std::string password;
    int userId;
    bool isActive;
    static int uniqueUserId;
    Book **borrowedBooks;
    int borrowedBookCount;

public:
    friend class Transaction;
    User(std::string n, std::string p);
    void addInBorrowedBooks(Book *book);
    void removeInBorrowedBooks(Book *book);
    int getUserId() const;
    void setUserActiveStatus(bool status);
    bool getUserActiveStatus() const;
    std::string getUserName() const;
    std::string getUserPassword() const;
    ~User();
};