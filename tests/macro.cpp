#include <iostream>
#include <map>
#include <string>
#include <doctest/doctest.h>
#include <cppin/in.hpp>


TEST_CASE("check in macro") {
    float array[] = { 3.0f, 2.0f, 7.0f, 10.0f };  // NOLINT(modernize-avoid-c-arrays)
    auto two = 2.0f in array;
    auto fifty = 50.0f in array;
    auto ten = 10.0f in array;
    auto one = 1.0f in array;
    CHECK(two);
    CHECK(two.position() == &(array[1]));
    CHECK(ten);
    CHECK(ten.position() == &(array[3]));
    CHECK_FALSE(fifty);
    CHECK_FALSE(one);
}


TEST_CASE("readme example 1") {
    std::map<int, std::string> dict{{1, "one"}, {2, "two"}};
    if (auto p = 2 in dict) {
        std::cout << p.position()->second << "\n";  // prints: "two"
    }
}
