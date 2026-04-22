#include "MainLibrary.h"
#include <iostream>

using namespace std;

int MainLibrary::totalBooksInMain = 0;
int MainLibrary::totalUsersInMain = 0;
int MainLibrary::activeUsersInMain = 0;
int MainLibrary::totalActiveBranches = 0;

MainLibrary::MainLibrary(int c, string ln, int bCap, int uCap) : Library(ln, bCap, uCap) {
    branchCount = 0;
    branchCapacity = c;
    branches = new BranchLibrary *[branchCapacity];
}

bool MainLibrary::branchExists(BranchLibrary *branch) {
    for (int i = 0; i < branchCount; i++) {
        if (branch->getBranchId() == branches[i]->getBranchId()) {
            return true;
        }
    }
    return false;
}

void MainLibrary::connectBranch(BranchLibrary *branch) {
    if (branchCount < branchCapacity) {
        branches[branchCount] = branch;
        branchCount++;
        cout << "Branch connected to Main Library Successfully" << endl;
    } else {
        cout << "Cannot hold more than " << branchCapacity << " branches" << endl;
    }
}

void MainLibrary::disconnectBranch(BranchLibrary *branch) {
    int index = -1;
    for (int i = 0; i < branchCount; i++) {
        if (branch->getBranchId() == branches[i]->getBranchId()) {
            index = i;
        }
    }

    if (index != -1) {
        for (int i = index; i < branchCount - 1; i++) {
            branches[i] = branches[i + 1];
        }
        branchCount--;
        cout << "Branch disconnected from Main Library" << endl;
    }
}

void MainLibrary::activateBranch(BranchLibrary *branch) {
    if (branchExists(branch)) {
        branch->setBranchStatus(true);
        totalActiveBranches++;
        cout << "Branch activated" << endl;
    }
}

void MainLibrary::deactivateBranch(BranchLibrary *branch) {
    if (branchExists(branch)) {
        branch->setBranchStatus(false);
        totalActiveBranches--;
        cout << "Branch deactivated" << endl;
    }
}

void MainLibrary::addBook(Book *book) {
    if (bookCount < bookCapacity) {
        books[bookCount] = book;
        bookCount++;
        totalBooksInMain++;
        cout << "Book added successfully" << endl;
    } else {
        cout << "Max inventory capacity reached" << endl;
    }
}

void MainLibrary::RegisterUser(User *user) {
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
        totalUsersInMain++;
    }
}

void MainLibrary::loginUser(User *user) {
    if (userExists(user)) {
        if (user->getUserActiveStatus() == false) {
            user->setUserActiveStatus(true);
            activeUsersInMain++;
            cout << "Login successful" << endl;
        } else {
            cout << "Login failed, User is already logged in" << endl;
        }
    } else {
        cout << "Login failed, no such user exists." << endl;
    }
}

void MainLibrary::logoutUser(User *user) {
    if (userExists(user)) {
        if (user->getUserActiveStatus() == true) {
            user->setUserActiveStatus(false);
            activeUsersInMain--;
            cout << "Logout Successful" << endl;
        } else {
            cout << "Error Logging out, account is not currently logged in" << endl;
        }
    } else {
        cout << "Error Logging out, User does not exist" << endl;
    }
}

MainLibrary::~MainLibrary() {
    for (int i = 0; i < branchCount; i++) {
        delete branches[i];
    }
    delete[] branches;
}