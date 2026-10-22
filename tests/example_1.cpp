#include <iostream>
#include <map>
#include <string>

#include <doctest/doctest.h>

#include <cppin/in.hpp>

TEST_CASE("readme example 1") {
    using mad::cppin::in_;

    std::map<int, std::string> dict{{1, "one"}, {2, "two"}};
    if (auto p = 2 << in_ << dict) {
        std::cout << (*p)->second << "\n";  // prints: "two"
    }
}
