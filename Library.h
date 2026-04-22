#pragma once
#include <string>
#include "Book.h"
#include "User.h"
#include "Transaction.h"

class Library {
protected:
    std::string libraryName;
    Book **books;
    User **registeredUsers;
    Transaction transactions[100]; 
    int transactionCount;
    int bookCapacity;
    int bookCount;
    int userCapacity;
    int userCount;

public:
    friend class Transaction;

    Library(std::string ln, int bCap, int uCap);
    virtual void addBook(Book *book) = 0;
    virtual void RegisterUser(User *user) = 0;
    virtual void loginUser(User *user) = 0;
    virtual void logoutUser(User *user) = 0;

    bool userExists(User *user);
    void borrowBook(Book *book, User *user, Transaction& t);
    void performTransaction(Transaction& transaction, Book &book, User &user, std::string transactionType);
    void returnBook(Book *book, User *user, Transaction& t);
    void AIBookrecommendation(User* user);
    ~Library();
};