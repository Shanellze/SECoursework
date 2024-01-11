#include <iostream>
#include <fstream>
#include <sstream>
#include "librarySystem.h"
#include <string>
#include <vector>
#include <limits>
using namespace std;

vector<Member*> members;


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
    int memberID;
    string name;
    string address;
    string email;

    //Collecting data on the member
    memberID = members.size();

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter address: ";
    cin >> address;

    cout << "Enter email: ";
    cin >> email;

    //Creating the member and adding it to the list of members
    members.push_back(new Member(memberID++, name, address, email));

    //Displaying the account details
    cout << "\nMember created:\n";
    cout << "ID: " << memberID << "\n";
    cout << "Name: " << name << "\n";
    cout << "Address: " << address << "\n";
    cout << "Email: " << email << "\n";
    
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

Date Book::getDueDate() {
    return dueDate;
}

void Book::setDueDate(Date dueDate) {
    this->dueDate = dueDate;
}


//Methods
void Book::returnBook() {
    borrower = nullptr;
    Date emptyDate;
    setDueDate(emptyDate);
}
void Book::borrowBook(Member* borrower, Date dueDate) {
    this->borrower = borrower;
    setDueDate(dueDate);
}



int main() {
    //Library librarian data
    Librarian librarian(1, "Shanell", "15 Widmore Rd, Bromley, BR1 1RL", "shanellze@library.com", 40000);

    //Library member data
    members.push_back(new Member(1, "Star", "address", "star@library.com"));
    members.push_back(new Member(2, "Night", "address", "Night@library.com"));
    members.push_back(new Member(3, "Rain", "address", "Rain@library.com"));
    members.push_back(new Member(4, "light", "address", "light@library.com"));

    //Load books
    string filename;
    filename = "library_books.csv";

    vector<Book*> libraryBooks;
    ifstream file(filename);
    string line, temp;
    int bookID;
    string bookName, authorFirstName, authorLastName;

    //Unable to open file
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    // Skip the header line
    getline(file, line);

    //Reading the file
    while (getline(file, line)) {
        stringstream ss(line);

        getline(ss, temp, ','); 
        bookID = stoi(temp);
        getline(ss, bookName, ',');
        getline(ss, temp, ',');
        getline(ss, authorFirstName, ',');
        getline(ss, authorLastName, ',');
        getline(ss, temp, ',');

        // Create a Book object and add it to the vector
        libraryBooks.push_back(new Book(bookID, bookName, authorFirstName, authorLastName));
    }


    cout << "Welcome to the library system.\n" << endl;

    //Gathering user input
    int userInput;
    int userMemberID;
    int userBookID;
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


    //Input Handling
    switch(userInput){
        case 1:
            cout << "Add a new member selected.\n" << endl;
            break;
        case 2:
            cout << "Issue a book selected.\n" << endl;
            break;
        case 3:
            cout << "Return a book selected.\n" << endl;
            break;
        case 4:
            cout << "Display all borrowed books selected.\n" << endl;
            break;
    }

    if (userInput == 1) {
        //Add a new member
        librarian.addMember();
    }
    else if (userInput == 2 || userInput == 3 || userInput == 4) {
        bool validMemberID = false;
        while (!validMemberID) {
            cout << "Enter Member ID: ";
            cin >> userMemberID;

            // Check if the entered Member ID exists in the members vector
            validMemberID = false;
            for (auto& member : members) {
                if (member->getMemberID() == userMemberID) {
                    validMemberID = true;
                    break;
                }
            }

            if (!validMemberID) {
                cout << "Invalid Member ID. Please try again." << endl;
            } else {
                if (userInput == 2 || userInput == 3){
                    bool validBookID = false;
                    while (!validBookID) {

                        cout << "Enter Book ID: ";
                        cin >> userBookID;

                        // Check if the entered Book ID exists in the books vector
                        validBookID = false;
                        for (auto& book : libraryBooks) {
                            if (book->getBookID() == userBookID) {
                                validBookID = true;
                                break;
                            }
                        }

                        if (!validBookID) {
                            cout << "Invalid Book ID. Please try again." << endl;
                        } else {
                            if (userInput == 2) {
                                //Issue a book to a member
                                librarian.issueBook(userMemberID, userBookID);
                            } else if (userInput == 3) {
                                //Return a book 
                                librarian.returnBook(userMemberID, userBookID);
                            } 
                        }
                    }
                } else if (userInput == 4) {
                    //Display all borrowed books of a member
                    librarian.displayBorrowedBooks(userMemberID);
                }
            }
        }
    }
    else if (userInput == 5) {
        cout << "Exiting the program." << endl;
    }


    return 0;
}