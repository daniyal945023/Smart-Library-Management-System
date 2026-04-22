#pragma once
#include "Library.h"
#include "BranchLibrary.h"
#include <string>

class MainLibrary : public Library {
private:
    BranchLibrary **branches;
    static int totalBooksInMain;
    static int totalUsersInMain;
    static int activeUsersInMain;
    static int totalActiveBranches;
    int branchCount;
    int branchCapacity;

public:
    MainLibrary(int c, std::string ln, int bCap, int uCap);
    bool branchExists(BranchLibrary *branch);
    void connectBranch(BranchLibrary *branch);
    void disconnectBranch(BranchLibrary *branch);
    void activateBranch(BranchLibrary *branch);
    void deactivateBranch(BranchLibrary *branch);
    void addBook(Book *book);
    void RegisterUser(User *user);
    void loginUser(User *user);
    void logoutUser(User *user);
    ~MainLibrary();
};