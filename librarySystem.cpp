#include <iostream>
#include "librarySystem.h"
#include <string>
#include <vector>
#include <limits>
using namespace std;


//Class Person
Person::Person(string name, string address, string email){
    this->name = name;
    this->address = address;
    this->email = email;
}

Person::~Person()
{
}


//Getter and setter methods
string Person::getName() {
    return name;
}

void Person::setName(string name) {
    this->name = name;
}

string Person::getAddress() {
    return address;
}

void Person::setAddress(string address) {
    this->address = address;
}

string Person::getEmail() {
    return email;
}

void Person::setEmail(string email) {
    this->email = email;
}


//Class Librarian
Librarian::Librarian(int staffID, string name, string address, string email, int salary) : Person(name, address, email), staffID(staffID), salary(salary) {
}


//Methods
void Librarian::addMember() {
}

void Librarian::issueBook(int memberID, int bookID) {
}

void Librarian::returnBook(int memberID, int bookID) {
}

void Librarian::displayBorrowedBooks(int memberID) {
}

void Librarian::calcFine(int memberID) {
}


//Getter and setter methods
int Librarian::getStaffID() {
    return staffID;
}

void Librarian::setStaffID(int staffID) {
    this->staffID = staffID;
}

int Librarian::getSalary() {
    return salary;
}

void Librarian::setSalary(int salary) {
    this->salary = salary;
}


//Class Member
Member::Member(int memberID, string name, string address, string email) : Person(name, address, email), memberID(memberID) {
}


//Getter and setter methods
int Member::getMemberID() {
    return memberID;
}

vector<Book*> Member::getBooksBorrowed() {
    return booksLoaned;
}

void Member::setBooksBorrowed(Book* book) {
    booksLoaned.push_back(book);
}


//Class Book
Book::Book(int bookID, string bookName, string authorFirstName, string authorLastName){
    this->bookID = bookID;
    this->bookName = bookName;
    this->authorFirstName = authorFirstName;
    this->authorLastName = authorLastName;
}

Book::~Book() { 
}


//Getters and setters methods
int Book::getBookID() {
    return bookID;
}

string Book::getBookName() {
    return bookName;
}

string Book::getAuthorFirstName() {
    return authorFirstName;
}

string Book::getAuthorLastName() {
    return authorLastName;
}

string Book::getDueDate() {
    return dueDate;
}

void Book::setDueDate(string dueDate) {
    this->dueDate = dueDate;
}


//Methods
void Book::returnBook() {
    borrower = nullptr;
    setDueDate("");
}
void Book::borrowBook(Member* borrower, string dueDate) {
    this->borrower = borrower;
    setDueDate(dueDate);
}



int main() {
    int userInput;

    cout << "Welcome to the library system.\n" << endl;

    bool validInput = false;
    while (!validInput) {
        cout << "[1] ADD A NEW MEMBER\n";
        cout << "[2] ISSUE A BOOK\n";
        cout << "[3] RETURN A BOOK\n";
        cout << "[4] DISPLAY ALL BORROWED BOOKS\n";
        cout << "[5] EXIT\n";
        cout << "\nENTER YOUR CHOICE HERE: ";
        cin >> userInput;

        if (cin.fail() || userInput < 1 || userInput > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter a number between 1 and 5.\n" << endl;
        } else {
            validInput = true;
        }
    }


    return 0;
}