#include "Transaction.h"
#include <iostream>

using namespace std;

int Transaction::uniqueTransactionID = 330;

Transaction::Transaction() {
    isSuccessful = false;
}

void Transaction::displayTransaction(Book &book, User &user, string type) {
    cout << "User Name: " << user.name << endl;
    cout << "User ID: " << user.userId << endl;
    cout << "Book Name: " << book.title << endl;
    cout << "Book ID: " << book.bookId << endl;
    cout << "Transaction Type: " << type << endl;
    cout << "Transaction ID: " << transactionID << endl;
}

void Transaction::setTransactionStatus(bool status) {
    isSuccessful = status;
}

void Transaction::generateNewID() {
    transactionID = uniqueTransactionID;
    uniqueTransactionID++;
}