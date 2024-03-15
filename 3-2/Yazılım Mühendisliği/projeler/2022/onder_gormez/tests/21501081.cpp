#include <catch2/catch_test_macros.hpp>

#include <iostream>

// #include "Student.h"

// Student myStudent;
//
// myStudent.updateName("Hakki");
// REQUIRE(myStudent.getName() == "Hakki");

TEST_CASE("21501081 - ENES DOĞAN ŞANLI", "[21501081]")
{
    // For each section, vector v is a new:
    std::vector<int> v(5);
    std::cout << "Hello world Enes" << std::endl;

    SECTION("name")
    {
        REQUIRE(v.size() == 5);
    }

    SECTION("TODO: Section description here", "[]")
    {
        REQUIRE(v.size() == 5);
    }
}
