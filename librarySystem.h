#ifndef _LIBRARYSYSTEM_H_
#define _LIBRARYSYSTEM_H_

#include <iostream>
#include <string>
#include <vector>

class Person {
  std::string name;
  std::string address;
  std::string email;
public:
  Person(std::string name, std::string address, std::string email);
  virtual ~Person();

  std::string getName();
  void setName(std::string name);
  
  std::string getAddress();
  void setAddress(std::string address);
  
  std::string getEmail();
  void setEmail(std::string email);
};

class Librarian : public Person {
 private:
  int staffID;
  int salary;
 public:
  Librarian(int staffID, std::string name, std::string address, std::string email, int salary);
    
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
    std::vector<Book*> booksLoaned; //CHECK THIS

public:
    Member(int memberID, std::string name, std::string address, std::string email);
    
    int getMemberID();

    std::vector<Book*> getBooksBorrowed(); //CHECK THIS
    void setBooksBorrowed(Book* book); //CHECK THIS
};

class Book {
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    std::string dueDate; 
    Member* borrower; // FIX THIS

public:
    Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName);
    virtual ~Book();
    
    int getBookID(); 
    std::string getBookName();
    std::string getAuthorFirstName();
    std::string getAuthorLastName();

    std::string getDueDate(); 
    void setDueDate(std::string dueDate); 

    void returnBook();
    void borrowBook(Member* borrower, std::string dueDate); // FIX THIS
};

#endif