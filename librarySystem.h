#ifndef _LIBRARYSYSTEM_H_
#define _LIBRARYSYSTEM_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
  string name;
  string address;
  string email;
public:
  Person(string name, string address, string email);
  virtual ~Person();

  string getName();
  void setName(string name);
  
  string getAddress();
  void setAddress(string address);
  
  string getEmail();
  void setEmail(string email);
};

class Librarian : public Person {
 private:
  int staffID;
  int salary;
 public:
  Librarian(int staffID, string name, string address, string email, int salary);
    
    void addMember();
    void issueBook(int memberID, int bookID);
    void returnBook(int memberID, int bookID);
    void displayBorrowedBooks(int memberID);
    void calcFine(int memberID);
    
    int getStaffID();
    void setStaffID(int staffID);

    int getSalary();
    void setSalary(int salary);
};

class Member : public Person {
private:
    int memberID;
    vector<Book*> booksLoaned; 

public:
    Member(int memberID, string name, string address, string email);
    
    int getMemberID();

    vector<Book*> getBooksBorrowed(); 
    void setBooksBorrowed(Book* book); 
};

class Book {
private:
    int bookID;
    string bookName;
    string authorFirstName;
    string authorLastName;
    string bookType;
    string dueDate; 
    Member* borrower; 

public:
    Book(int bookID, string bookName, string authorFirstName, string authorLastName);
    virtual ~Book();
    
    int getBookID(); 
    string getBookName();
    string getAuthorFirstName();
    string getAuthorLastName();

    string getDueDate(); 
    void setDueDate(string dueDate); 

    void returnBook();
    void borrowBook(Member* borrower, string dueDate); 
};

#endif