#include "Book.h"

using namespace std;

int Book::uniqueBookId = 220;

Book::Book() {
    title = "";
    author = "";
    bookId = uniqueBookId;
    uniqueBookId++;
    isAvailable = false;
}

Book::Book(string t, string a) {
    title = t;
    author = a;
    bookId = uniqueBookId;
    uniqueBookId++;
    isAvailable = false;
}

int Book::getBookId() const {
    return bookId;
}

void Book::setAvailability(bool status) {
    isAvailable = status;
}

bool Book::isBookAvailable() const {
    return isAvailable;
}

string Book::getBookTitle() {
    return title;
}

string Book::getBookAuthor() const {
    return author;
}