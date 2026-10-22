#include <iostream>
#include <map>
#include <string>

#include <doctest/doctest.h>

#include <cppin/in.hpp>

TEST_CASE("check in macro") {
    float array[] = {3.0f, 2.0f, 7.0f, 10.0f};  // NOLINT(modernize-avoid-c-arrays)
    auto two = 2.0f in array;
    auto fifty = 50.0f in array;
    auto ten = 10.0f in array;
    auto one = 1.0f in array;
    REQUIRE(two);
    CHECK(two == &(array[1]));
    REQUIRE(ten);
    CHECK(ten == &(array[3]));
    CHECK_FALSE(fifty);
    CHECK_FALSE(one);
}

TEST_CASE("readme example 2") {
    std::map<int, std::string> dict{{1, "one"}, {2, "two"}};
    if (auto p = 2 in dict) {
        std::cout << (*p)->second << "\n";  // prints: "two"
    }
}
