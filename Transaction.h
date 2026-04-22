#pragma once
#include <string>
#include "Book.h"
#include "User.h"

class Transaction {
private:
    int transactionID;
    bool isSuccessful;
    static int uniqueTransactionID;

public:
    Transaction();
    void displayTransaction(Book &book, User &user, std::string type);
    void setTransactionStatus(bool status);
    void generateNewID();
};