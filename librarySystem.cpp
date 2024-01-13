#include <iostream>
#include <fstream>
#include <sstream>
#include "librarySystem.h"
#include <string>
#include <vector>
#include <limits>
#include <chrono>
using namespace std;

vector<Member*> members;
vector<Book*> libraryBooks;

Date calcDueDate();
Date getCurrentDate();
int dateToDays(Date date);


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
    memberID++;

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter address: ";
    cin >> address;

    cout << "Enter email: ";
    cin >> email;

    //Creating the member and adding it to the list of members
    members.push_back(new Member(memberID, name, address, email));

    //Displaying the account details
    cout << "\nMember created:\n";
    cout << "ID: " << memberID << "\n";
    cout << "Name: " << name << "\n";
    cout << "Address: " << address << "\n";
    cout << "Email: " << email << "\n";
    
}

void Librarian::issueBook(int memberID, int bookID) {
    //Find the member
    for (auto& member : members) {
        if (member->getMemberID() == memberID) {

            //Find the book
            for (auto& book : libraryBooks) {
                if (book->getBookID() == bookID) {
                    //Issue the book
                    Date dueDate = calcDueDate();
                    book->borrowBook(member, dueDate);
                    member->setBooksBorrowed(book);

                    //Display issued book
                    cout << "\n" << book->getBookName() << " by " << book->getAuthorFirstName() << " " << book->getAuthorLastName() << " has been issued successfully." << endl;
                    cout << "The book will be due on: " << dueDate.day << "/" << dueDate.month << "/" << dueDate.year << endl;
                    break;
                    
                }
            }

        }
    }

}

void Librarian::returnBook(int memberID, int bookID) {
    bool bookFound = false;
    Date currentDate = getCurrentDate();
    int finePerDay = 1;
    int totalFine = 0;

    //Find the member
    for (auto& member : members) {
        if (member->getMemberID() == memberID) {
            vector<Book*> borrowedBooks = member->getBooksBorrowed();
            
            //Check whether the member has borrowed any books
            if (borrowedBooks.empty()) {
                //No books borrowed
                cout << "\nThe member has not borrowed any books." << endl;
                return;
            } else {
                //There is a book to be returned
                for (auto& book : borrowedBooks) {
                    if (book->getBookID() == bookID) {
                        Date dueDate = book->getDueDate();

                        //Calculate the number of days overdue
                        int daysOverdue = (dateToDays(currentDate) - dateToDays(dueDate)); 

                        // Check if the book is overdue
                        if (daysOverdue > 0) {
                            //Calculate the fine
                            int fine = daysOverdue * finePerDay;
                            totalFine += fine;

                            //Display fine details
                            cout << "Book ID: " << book->getBookID() << ", Overdue by: " << daysOverdue << " days, Fine: £" << fine << endl;
                        }

                        //Return the book
                        cout << "\nBook Returned: " << book->getBookName() << endl;
                        book->returnBook();
                        bookFound = true;
                        break;
                    } 
                }

                if (!bookFound) {
                    cout << "\nThe member has not borrowed this book." << endl;
                }
            }
            break;
        }
    }
}

void Librarian::displayBorrowedBooks(int memberID) {
    //Find the member
    for (auto& member : members) {
        if (member->getMemberID() == memberID) {
            vector<Book*> borrowedBooks = member->getBooksBorrowed();
            
            //Check whether the member has borrowed any books
            if (borrowedBooks.empty()) {
                //No books borrowed
                cout << "\nThe member has not borrowed any books." << endl;
            } else {
                //Display all borrowed books
                cout << "\nBorrowed books: " << endl;
                for (auto& book : borrowedBooks) {
                    cout << "Book ID: " << book->getBookID() << ", Name: " << book->getBookName() 
                         << ", Author: " << book->getAuthorFirstName() << " " << book->getAuthorLastName() << endl;
                }
            }
            break;
        }
    }

}

void Librarian::calcFine(int memberID) {
    Date currentDate = getCurrentDate();
    int finePerDay = 1;
    int totalFine = 0;

    //Find the member
    for (auto& member : members) {
        if (member->getMemberID() == memberID) {
            vector<Book*> borrowedBooks = member->getBooksBorrowed();
            
            cout << endl;

            //Iterate through each borrowed book
            for (auto& book : borrowedBooks) {
                Date dueDate = book->getDueDate();

                //Calculate the number of days overdue
                int daysOverdue = (dateToDays(currentDate) - dateToDays(dueDate)); 

                // Check if the book is overdue
                if (daysOverdue > 0) {
                    //Calculate the fine
                    int fine = daysOverdue * finePerDay;
                    totalFine += fine;

                    //Display fine details
                    cout << "Book ID: " << book->getBookID() << ", Overdue by: " << daysOverdue << " days, Fine: £" << fine << endl;
                }
            }
            break;
        }
    }

    //Display the total fine
    cout << "\nTotal fine for Member ID " << memberID << ": £" << totalFine << endl;
  
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


Date getCurrentDate() {
    auto now = std::chrono::system_clock::now();
    auto currentTime = std::chrono::system_clock::to_time_t(now);

    tm* localTime = std::localtime(&currentTime);

    Date currentDate;
    currentDate.day = localTime->tm_mday;
    currentDate.month = localTime->tm_mon + 1;
    currentDate.year = localTime->tm_year + 1900;

    return currentDate;
}


Date calcDueDate() {
    Date dueDate = getCurrentDate();

    //Adding 3 days to the current date
    dueDate.day += 3;

    //Days in a month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //Check for leap year
    if ((dueDate.year % 4 == 0 && dueDate.year % 100 != 0) || (dueDate.year % 400 == 0)){
        daysInMonth[1] = 29;
    }

    //Adjust the day and month if necessary
    if (dueDate.day > daysInMonth[dueDate.month - 1]) {
        dueDate.day -= daysInMonth[dueDate.month - 1];
        dueDate.month++;

        //Adjust the year if necessary
        if (dueDate.month > 12) {
            dueDate.month = 1;
            dueDate.year++;
        }
    }

    return dueDate;
}

int dateToDays(Date date) {
    //Days in a month    
     int daysInMonth[2][12] = {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

    //Calculating the days
    int year = date.year - 1; 
    int days = year * 365 + year / 4 - year / 100 + year / 400; 

    bool isLeapYear = (date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0);
    for (int i = 0; i < date.month - 1; ++i) {
        days += daysInMonth[isLeapYear][i];
    }

    days += date.day;

    return days;
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


    //Library member details data
    members[1]->setBooksBorrowed(libraryBooks[0]); 
    members[1]->setBooksBorrowed(libraryBooks[1]); 

    Date dueDate1 = {2023, 1, 15};
    Date dueDate2 = {2023, 12, 20};
    libraryBooks[0]->borrowBook(members[1], dueDate1);
    libraryBooks[1]->borrowBook(members[1], dueDate2);

    cout << "Welcome to the library system." << endl;

    bool running = true;
    while (running) {
        //Gathering user input
        int userInput;
        int userMemberID;
        int userBookID;
        bool validInput = false;
        while (!validInput) {
            cout << "\n ---------------------------------" << endl;
            cout << "|    Library Management System    |" << endl;
            cout << " ---------------------------------" << endl;
            cout << "| [1] ADD A NEW MEMBER            |\n";
            cout << "| [2] ISSUE A BOOK                |\n";
            cout << "| [3] RETURN A BOOK               |\n";
            cout << "| [4] DISPLAY ALL BORROWED BOOKS  |\n";
            cout << "| [5] CALCULATE FINE              |\n";
            cout << "| [6] EXIT                        |\n";
            cout << " ---------------------------------" << endl;
            cout << "\nENTER YOUR CHOICE HERE: ";
            cin >> userInput;

            if (cin.fail() || userInput < 1 || userInput > 6) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input, please enter a number between 1 and 6.\n" << endl;
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
            case 5:
                cout << "Calculate fine selected.\n" << endl;
                break;
        }

        if (userInput == 1) {
            //Add a new member
            librarian.addMember();
        }
        else if (userInput == 2 || userInput == 3 || userInput == 4 || userInput == 5) {
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
                    cout << "Invalid Member ID. Please try again.\n" << endl;
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
                                cout << "Invalid Book ID. Please try again.\n" << endl;
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
                    } else if (userInput == 5) {
                        //Calculate a member's fine
                        librarian.calcFine(userMemberID);
                    }
                }
            }
        }
        else if (userInput == 6) {
            cout << "Exiting the program." << endl;
            running = false;
        }
    }


    return 0;
}