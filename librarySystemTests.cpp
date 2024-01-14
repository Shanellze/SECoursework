#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "librarySystem.h" 

TEST_CASE("test librarian", "[Librarian]") {
    Librarian librarian(1, "TestLibrarian", "TestAddress", "test@email.com", 30000);
    REQUIRE(librarian.getStaffID() == 1);
    REQUIRE(librarian.getSalary() == 30000);
}
