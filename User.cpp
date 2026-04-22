#include "User.h"

using namespace std;

int User::uniqueUserId = 110;

User::User(string n, string p) {
    borrowedBookCount = 0;
    borrowedBooks = new Book *[5];
    name = n;
    password = p;
    isActive = false;
    userId = uniqueUserId;
    uniqueUserId++;
}

void User::addInBorrowedBooks(Book *book) {
    if (borrowedBookCount < 5) {
        borrowedBooks[borrowedBookCount] = book;
        borrowedBookCount++;
    }
}

void User::removeInBorrowedBooks(Book *book) {
    int foundIndex = -1;
    for (int i = 0; i < borrowedBookCount; i++) {
        if (borrowedBooks[i]->getBookId() == book->getBookId()) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < borrowedBookCount - 1; i++) {
            borrowedBooks[i] = borrowedBooks[i + 1];
        }
        borrowedBookCount--;
    }
}

int User::getUserId() const {
    return userId;
}

void User::setUserActiveStatus(bool status) {
    isActive = status;
}

bool User::getUserActiveStatus() const {
    return isActive;
}

string User::getUserName() const {
    return name;
}

string User::getUserPassword() const {
    return password;
}

User::~User() {
    delete[] borrowedBooks;
}