#include "BranchLibrary.h"
#include <iostream>

using namespace std;

int BranchLibrary::totalBooksInBranch = 0;
int BranchLibrary::totalUsersInBranch = 0;
int BranchLibrary::activeUsersInBranch = 0;
int BranchLibrary::uniqueBranchId = 550;

BranchLibrary::BranchLibrary(string ln, int bCap, int uCap) : Library(ln, bCap, uCap) {
    branchId = uniqueBranchId;
    uniqueBranchId++;
    isBranchActive = false;
}

void BranchLibrary::addBook(Book *book) {
    if (bookCount < bookCapacity) {
        books[bookCount] = book;
        bookCount++;
        totalBooksInBranch++;
        cout << "Book added successfully" << endl;
    } else {
        cout << "Max inventory capacity reached" << endl;
    }
}

void BranchLibrary::RegisterUser(User *user) {
    int found = 0;
    for (int i = 0; i < userCount; i++) {
        if ((*registeredUsers[i]).getUserId() == (*user).getUserId()) {
            cout << "User already registered" << endl;
            found = 1;
            break;
        }
    }

    if ((userCount < userCapacity) && (found == 0)) {
        registeredUsers[userCount] = user;
        userCount++;
        totalUsersInBranch++;
    }
}

void BranchLibrary::loginUser(User *user) {
    if (isBranchActive) {
        if (userExists(user)) {
            if (user->getUserActiveStatus() == false) {
                user->setUserActiveStatus(true);
                activeUsersInBranch++;
                cout << "Login successful" << endl;
            } else {
                cout << "Login failed, User is already logged in" << endl;
            }
        } else {
            cout << "Login failed, no such user exists." << endl;
        }
    } else {
        cout << "Branch offline" << endl;
    }
}

void BranchLibrary::logoutUser(User *user) {
    if (userExists(user)) {
        if (user->getUserActiveStatus() == true) {
            user->setUserActiveStatus(false);
            activeUsersInBranch--;
            cout << "Logout Successful" << endl;
        } else {
            cout << "Error Logging out, account is not currently logged in" << endl;
        }
    } else {
        cout << "Error Logging out, User does not exist" << endl;
    }
}

int BranchLibrary::getBranchId() const {
    return branchId;
}

void BranchLibrary::setBranchStatus(bool status) {
    isBranchActive = status;
}