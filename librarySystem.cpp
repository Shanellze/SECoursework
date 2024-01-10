#include <iostream>
#include "librarySystem.h"
#include <string>
#include <vector>
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
Librarian::Librarian(int staffID, string name, string address, string email, int salary) : Person(name, address, email) {
    this->staffID = staffID;
    this->name = name;
    this->address = address;
    this->email = email;
    this->salary = salary;
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
Member::Member(int memberID, string name, string address, string email) : Person(name, address, email) {
    this->memberID = memberID;
    this->name = name;
    this->address = address;
    this->email = email;
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
    

}