#include <iostream>
#include <string>
#include <fstream>

// Include your newly modular headers
#include "Book.h"
#include "User.h"
#include "Transaction.h"
#include "Library.h"
#include "BranchLibrary.h"
#include "MainLibrary.h"

using namespace std;

int main() {
    // Heap allocate the library so it handles its own destructors
    MainLibrary* myLib = new MainLibrary(5, "Central City Library", 100, 100);

    // Tracking arrays in main() so we can fetch pointers based on user input IDs
    Book* trackedBooks[100];
    int trackedBookCount = 0;
    User* trackedUsers[100];
    int trackedUserCount = 0;

    // --- DATA LOADING PHASE ---
    cout << "Loading previous library data...\n";
    ifstream bookFile("books.txt");
    if (bookFile.is_open()) {
        string title, author, availStr;
        while (getline(bookFile, title, '|')) {
            getline(bookFile, author, '|');
            getline(bookFile, availStr);
            if (title.empty()) continue;
            
            Book* b = new Book(title, author);
            b->setAvailability(availStr == "1");
            myLib->addBook(b); 
            trackedBooks[trackedBookCount++] = b;
        }
        bookFile.close();
    }

    ifstream userFile("users.txt");
    if (userFile.is_open()) {
        string name, password, activeStr;
        while (getline(userFile, name, '|')) {
            getline(userFile, password, '|');
            getline(userFile, activeStr);
            if (name.empty()) continue;

            User* u = new User(name, password);
            u->setUserActiveStatus(activeStr == "1");
            myLib->RegisterUser(u);
            trackedUsers[trackedUserCount++] = u;
        }
        userFile.close();
    }
    cout << "Loading complete.\n";
    // --------------------------

    int choice = 0;

    while (choice != 8) {
        cout << "\n========================================\n";
        cout << "       LIBRARY MANAGEMENT SYSTEM        \n";
        cout << "========================================\n";
        cout << "1. Add a Book to Library\n";
        cout << "2. Register a New User\n";
        cout << "3. Login User\n";
        cout << "4. Logout User\n";
        cout << "5. Borrow a Book\n";
        cout << "6. Return a Book\n";
        cout << "7. Get AI Book Recommendation\n";
        cout << "8. Exit and Clean Up\n";
        cout << "----------------------------------------\n";
        cout << "Enter your choice: ";

        // Robust input handling to prevent infinite loops if a user types a letter
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n[!] Invalid input. Please enter a number.\n";
            continue;
        }
        cin.ignore(10000, '\n');

        switch (choice) {
            case 1: {
                string title, author;
                cout << "\nEnter Book Title: ";
                cin >> ws; 
                getline(cin, title);
                cout << "Enter Book Author: ";
                getline(cin, author);

                Book* newBook = new Book(title, author);
                newBook->setAvailability(true); 
                
                myLib->addBook(newBook);
                trackedBooks[trackedBookCount++] = newBook;
                
                cout << "[+] Book added successfully! Assigned Book ID: " << newBook->getBookId() << "\n";
                break;
            }
            case 2: {
                string name, password;
                cout << "\nEnter User Name: ";
                cin >> ws;
                getline(cin, name);
                cout << "Enter Password: ";
                cin >> password;

                User* newUser = new User(name, password);
                
                myLib->RegisterUser(newUser);
                trackedUsers[trackedUserCount++] = newUser;
                
                cout << "[+] User registered successfully! Assigned User ID: " << newUser->getUserId() << "\n";
                break;
            }
            case 3: {
                int uid;
                cout << "\nEnter User ID to login: ";
                cin >> uid;

                User* foundUser = nullptr;
                for (int i = 0; i < trackedUserCount; i++) {
                    if (trackedUsers[i]->getUserId() == uid) {
                        foundUser = trackedUsers[i];
                        break;
                    }
                }

                if (foundUser != nullptr) {
                    myLib->loginUser(foundUser);
                } else {
                    cout << "[-] User ID not found in system.\n";
                }
                break;
            }
            case 4: {
                int uid;
                cout << "\nEnter User ID to logout: ";
                cin >> uid;

                User* foundUser = nullptr;
                for (int i = 0; i < trackedUserCount; i++) {
                    if (trackedUsers[i]->getUserId() == uid) {
                        foundUser = trackedUsers[i];
                        break;
                    }
                }

                if (foundUser != nullptr) {
                    myLib->logoutUser(foundUser);
                } else {
                    cout << "[-] User ID not found in system.\n";
                }
                break;
            }
            case 5: {
                int uid, bid;
                cout << "\nEnter User ID: ";
                cin >> uid;
                cout << "Enter Book ID to borrow: ";
                cin >> bid;

                User* foundUser = nullptr;
                for (int i = 0; i < trackedUserCount; i++) {
                    if (trackedUsers[i]->getUserId() == uid) foundUser = trackedUsers[i];
                }

                Book* foundBook = nullptr;
                for (int i = 0; i < trackedBookCount; i++) {
                    if (trackedBooks[i]->getBookId() == bid) foundBook = trackedBooks[i];
                }

                if (foundUser && foundBook) {
                    Transaction t; 
                    cout << "\n--- Processing Borrow Transaction ---\n";
                    myLib->borrowBook(foundBook, foundUser, t);
                } else {
                    cout << "[-] Invalid User ID or Book ID.\n";
                }
                break;
            }
            case 6: {
                int uid, bid;
                cout << "\nEnter User ID: ";
                cin >> uid;
                cout << "Enter Book ID to return: ";
                cin >> bid;

                User* foundUser = nullptr;
                for (int i = 0; i < trackedUserCount; i++) {
                    if (trackedUsers[i]->getUserId() == uid) foundUser = trackedUsers[i];
                }

                Book* foundBook = nullptr;
                for (int i = 0; i < trackedBookCount; i++) {
                    if (trackedBooks[i]->getBookId() == bid) foundBook = trackedBooks[i];
                }

                if (foundUser && foundBook) {
                    Transaction t; 
                    cout << "\n--- Processing Return Transaction ---\n";
                    myLib->returnBook(foundBook, foundUser, t);
                } else {
                    cout << "[-] Invalid User ID or Book ID.\n";
                }
                break;
            }
            case 7: {
                int uid;
                cout << "\nEnter User ID for Recommendation: ";
                cin >> uid;

                User* foundUser = nullptr;
                for (int i = 0; i < trackedUserCount; i++) {
                    if (trackedUsers[i]->getUserId() == uid) {
                        foundUser = trackedUsers[i];
                        break;
                    }
                }

                if (foundUser != nullptr) {
                    myLib->AIBookrecommendation(foundUser);
                } else {
                    cout << "[-] User ID not found in system.\n";
                }
                break;
            }
            case 8: {
                cout << "\nSaving Data to files...\n";
                
                ofstream bOut("books.txt");
                for(int i = 0; i < trackedBookCount; ++i) {
                    bOut << trackedBooks[i]->getBookTitle() << "|" 
                         << trackedBooks[i]->getBookAuthor() << "|" 
                         << trackedBooks[i]->isBookAvailable() << "\n";
                }
                bOut.close();

                ofstream uOut("users.txt");
                for(int i = 0; i < trackedUserCount; ++i) {
                    uOut << trackedUsers[i]->getUserName() << "|" 
                         << trackedUsers[i]->getUserPassword() << "|" 
                         << trackedUsers[i]->getUserActiveStatus() << "\n";
                }
                uOut.close();

                cout << "Data saved successfully. Cleaning up memory and exiting...\n";
                break;
            }
            default:
                cout << "\n[!] Invalid choice. Please select 1-8.\n";
        }
    }

    delete myLib; 
    
    return 0;
}