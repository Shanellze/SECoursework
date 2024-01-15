#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "librarySystem.cpp" 
#include "librarySystem.h" 


TEST_CASE("test person", "[person]") {
    Person person("TestPerson", "TestAddress", "Test@email.com");

    //Testing getter methods
    REQUIRE(person.getName() == "TestPerson");
    REQUIRE(person.getAddress() == "TestAddress");
    REQUIRE(person.getEmail() == "Test@email.com");

    //Testing setter methods
    person.setName("NewTestPerson");
    person.setAddress("NewTestAddress");
    person.setEmail("NewTest@email.com");

    REQUIRE(person.getName() == "NewTestPerson");
    REQUIRE(person.getAddress() == "NewTestAddress");
    REQUIRE(person.getEmail() == "NewTest@email.com");

    //Erroneous data
    REQUIRE_FALSE(person.getName() == "TestPerson");
    REQUIRE_FALSE(person.getAddress() == "TestAddress");
    REQUIRE_FALSE(person.getEmail() == "Test@email.com");
}

TEST_CASE("test librarian", "[Librarian]") {
    Librarian librarian(1, "TestLibrarian", "TestAddress", "Test@email.com", 30000);

    //Testing getter methods
    REQUIRE(librarian.getStaffID() == 1);
    REQUIRE(librarian.getSalary() == 30000);

    //Testing setter methods
    librarian.setStaffID(2);
    librarian.setSalary(15000);

    REQUIRE(librarian.getStaffID() == 2);
    REQUIRE(librarian.getSalary() == 15000);

    //Testing inherited methods
    REQUIRE(librarian.getName() == "TestLibrarian");
    REQUIRE(librarian.getAddress() == "TestAddress");
    REQUIRE(librarian.getEmail() == "Test@email.com");

    librarian.setName("NewTestLibrarian");
    librarian.setAddress("NewTestAddress");
    librarian.setEmail("NewTest@email.com");

    REQUIRE(librarian.getName() == "NewTestLibrarian");
    REQUIRE(librarian.getAddress() == "NewTestAddress");
    REQUIRE(librarian.getEmail() == "NewTest@email.com");

    //Erroneous data
    REQUIRE_FALSE(librarian.getStaffID() == 1);
    REQUIRE_FALSE(librarian.getSalary() == 30000);
    REQUIRE_FALSE(librarian.getName() == "TestLibrarian");
    REQUIRE_FALSE(librarian.getAddress() == "TestAddress");
    REQUIRE_FALSE(librarian.getEmail() == "Test@email.com");
}

TEST_CASE("test member", "[Member]") {
    Member member(1, "TestMember", "TestAddress", "Test@email.com");

    //Testing getter methods
    REQUIRE(member.getMemberID() == 1);

    //Testing inherited methods
    REQUIRE(member.getName() == "TestMember");
    REQUIRE(member.getAddress() == "TestAddress");
    REQUIRE(member.getEmail() == "Test@email.com");
    
    member.setName("NewTestMember");
    member.setAddress("NewTestAddress");
    member.setEmail("NewTest@email.com");

    REQUIRE(member.getName() == "NewTestMember");
    REQUIRE(member.getAddress() == "NewTestAddress");
    REQUIRE(member.getEmail() == "NewTest@email.com");

    //Erroneous data
    REQUIRE_FALSE(member.getMemberID() == 2);
    REQUIRE_FALSE(member.getName() == "TestMember");
    REQUIRE_FALSE(member.getAddress() == "TestAddress");
    REQUIRE_FALSE(member.getEmail() == "Test@email.com");
}

TEST_CASE("test book", "[Book]") {
    Book book(1, "TestBookName", "TestAuthorFirstName", "TestAuthorLastName");
    Date dueDate1 = {2023, 1, 15};
    book.setDueDate(dueDate1);

    //Testing getter methods
    REQUIRE(book.getBookID() == 1);
    REQUIRE(book.getBookName() == "TestBookName");
    REQUIRE(book.getAuthorFirstName() == "TestAuthorFirstName");
    REQUIRE(book.getAuthorLastName() == "TestAuthorLastName");

    //Testing setter methods
    REQUIRE(book.getDueDate().year == 2023);
    REQUIRE(book.getDueDate().month == 1);
    REQUIRE(book.getDueDate().day == 15);

    //Erroneous data
    REQUIRE_FALSE(book.getBookID() == 2);
    REQUIRE_FALSE(book.getBookName() == "TestBookName2");
    REQUIRE_FALSE(book.getAuthorFirstName() == "TestAuthorFirstName2");
    REQUIRE_FALSE(book.getAuthorLastName() == "TestAuthorLastName2");
    REQUIRE_FALSE(book.getDueDate().year == 2024);
    REQUIRE_FALSE(book.getDueDate().month == 8);
    REQUIRE_FALSE(book.getDueDate().day == 11);
}