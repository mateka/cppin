#include <iostream>
#include <map>
#include <string>

#include <doctest/doctest.h>

#define NO_IN_MACRO 1
#include <cppin/in.hpp>

TEST_CASE("readme example 2") {
    using namespace mad::cppin;

    std::map<int, std::string> dict{{1, "one"}, {2, "two"}};
    if (auto p = 2 << in_ << dict) {
        std::cout << (*p)->second << "\n";  // prints: "two"
    }
}
