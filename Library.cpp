#include "Library.h"
#include <iostream>
#include <random>

using namespace std;

Library::Library(string ln, int bCap, int uCap) : bookCount(0), userCount(0), transactionCount(0) {
    libraryName = ln;
    bookCapacity = bCap;
    userCapacity = uCap;
    books = new Book *[bookCapacity];
    registeredUsers = new User *[userCapacity];
}

bool Library::userExists(User *user) {
    for (int i = 0; i < userCount; i++) {
        if (registeredUsers[i]->getUserId() == user->getUserId()) {
            return true;
        }
    }
    return false;
}

void Library::borrowBook(Book *book, User *user, Transaction& t) {
    int foundAndAvailable = 0;
    string type = "Borrow";

    if (userExists(user) && user->getUserActiveStatus() == true) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i]->getBookId() == book->getBookId()) {
                if (books[i]->isBookAvailable()) {
                    cout << "Book is Available for issue" << endl;
                    books[i]->setAvailability(false);
                    foundAndAvailable = 1;
                } else {
                    cout << "Book not available for issue" << endl;
                }
            } else if ((books[i]->getBookId() != book->getBookId()) && (i == bookCount - 1)) {
                cout << "Book not found" << endl;
            }
        }

        if (foundAndAvailable) {
            user->addInBorrowedBooks(book);
            performTransaction(t, *book, *user, type);
        } else {
            cout << "Book either not found or not available" << endl;
        }
    } else {
        cout << "User does not exist" << endl;
    }
}

void Library::performTransaction(Transaction& transaction, Book &book, User &user, string transactionType) {
    if (transactionCount < 100) {
        transaction.generateNewID();
        transaction.setTransactionStatus(true);
        transactions[transactionCount] = transaction;
        transaction.displayTransaction(book, user, transactionType);
        transactionCount++;
    } else {
        cout << "Max transaction limit reached" << endl;
    }
}

void Library::returnBook(Book *book, User *user, Transaction& t) {
    int foundAndNotAvailable = 0;
    string type = "Return";

    if (userExists(user) && user->getUserActiveStatus() == true) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i]->getBookId() == book->getBookId()) {
                if (books[i]->isBookAvailable() == false) {
                    foundAndNotAvailable = 1;
                    cout << "Kindly return the Book here" << endl;
                    books[i]->setAvailability(true);
                } else {
                    cout << "Book already exists, cannot be returned" << endl;
                }
            } else if ((books[i]->getBookId() != book->getBookId()) && (i == bookCount - 1)) {
                cout << "Book not found" << endl;
            }
        }

        if (foundAndNotAvailable) {
            user->removeInBorrowedBooks(book);
            performTransaction(t, *book, *user, type);
        } else {
            cout << "Book either not found or cannot be returned" << endl;
        }
    } else {
        cout << "User does not exist" << endl;
    }
}

void Library::AIBookrecommendation(User* user) {
    if(userExists(user) && user->getUserActiveStatus()==true){
        if (bookCount == 0) {
            cout << "No books to recommend" << endl;
            return;
        }
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(0, bookCount - 1);
        int aiRecommendedIndex = distr(gen);
        cout << "Hi there, I recommend that you read " << books[aiRecommendedIndex]->getBookTitle() << endl;
    } else {
        cout<<"User either doesn't exist or isnt active. Login or register to use ai recommendation."<<endl;
    }
}

Library::~Library() {
    for (int i = 0; i < bookCount; i++) {
        delete books[i];
    }
    delete[] books;

    for (int i = 0; i < userCount; i++) {
        delete registeredUsers[i];
    }
    delete[] registeredUsers;
}