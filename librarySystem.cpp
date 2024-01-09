#include <iostream>
#include "librarySystem.h"
#include <vector>


//Class Person
Person::Person(std::string name, std::string address, std::string email){
    this->name = name;
    this->address = address;
    this->email = email;
}

Person::~Person()
{
}


//Getter and setter methods
std::string Person::getName() {
    return name;
}

void Person::setName(std::string name) {
    this->name = name;
}

std::string Person::getAddress() {
    return address;
}

void Person::setAddress(std::string address) {
    this->address = address;
}

std::string Person::getEmail() {
    return email;
}

void Person::setEmail(std::string email) {
    this->email = email;
}


//Class Librarian
Librarian::Librarian(int staffID, std::string name, std::string address, std::string email, int salary) : Person(name, address, email) {
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
Member::Member(int memberID, std::string name, std::string address, std::string email) : Person(name, address, email) {
    this->memberID = memberID;
    this->name = name;
    this->address = address;
    this->email = email;
}


//Getter and setter methods
int Member::getMemberID() {
    return memberID;
}

std::vector<Book*> Member::getBooksBorrowed() {
    return booksLoaned;
}

void Member::setBooksBorrowed(Book* book) {
    booksLoaned.push_back(book);
}


//Class Book
Book::Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName){
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

std::string Book::getBookName() {
    return bookName;
}

std::string Book::getAuthorFirstName() {
    return authorFirstName;
}

std::string Book::getAuthorLastName() {
    return authorLastName;
}

std::string Book::getDueDate() {
    return dueDate;
}

void Book::setDueDate(std::string dueDate) {
    this->dueDate = dueDate;
}


//Methods
void Book::returnBook() {
    borrower = nullptr;
    setDueDate("");
}
void Book::borrowBook(Member* borrower, std::string dueDate) {
    this->borrower = borrower;
    setDueDate(dueDate);
}



int main() {

}