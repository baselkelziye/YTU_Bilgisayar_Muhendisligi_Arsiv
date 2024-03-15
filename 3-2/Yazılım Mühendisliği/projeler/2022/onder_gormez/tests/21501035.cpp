#include <catch2/catch_test_macros.hpp>

#include <iostream>

TEST_CASE("21501035 - ÖNDER GÖRMEZ", "[21501035]")
{
    // For each section, vector v is a new:
    std::vector<int> v(5);
    std::cout << "Hello world Önder" << std::endl;

    SECTION("name")
    {
        REQUIRE(v.size() == 5);
    }

    SECTION("TODO: Section description here", "[]")
    {
        REQUIRE(v.size() == 5);
    }
}
