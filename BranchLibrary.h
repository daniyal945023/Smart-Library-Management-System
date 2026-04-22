#pragma once
#include "Library.h"
#include <string>

class BranchLibrary : public Library {
    bool isBranchActive;
    std::string location;
    int branchId;
    static int totalBooksInBranch;
    static int totalUsersInBranch;
    static int activeUsersInBranch;
    static int uniqueBranchId;

public:
    BranchLibrary(std::string ln, int bCap, int uCap);
    void addBook(Book *book);
    void RegisterUser(User *user);
    void loginUser(User *user);
    void logoutUser(User *user);
    int getBranchId() const;
    void setBranchStatus(bool status);
};