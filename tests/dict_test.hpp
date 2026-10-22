#include <utility>

#include <doctest/doctest.h>
#include <cppin/in.hpp>


TEST_CASE_TEMPLATE_DEFINE("check dict-like cases", TDict, dict_like_test_case) {
    TDict collection = TDict{ { 3, "three" }, { 2, "two" }, { 7, "seven" }, { 10, "ten" } };

    SUBCASE("present") {
        auto positive = GENERATE(std::pair{ 2, "two" }, std::pair{ 10, "ten" });
        auto positive_result = positive.first << mad::cppin::in_ << collection;
        REQUIRE(positive_result);
        CHECK(positive_result.position()->first == positive.first);
        CHECK(positive_result.position()->second == positive.second);
    }

    SUBCASE("absent") {
        auto negative = GENERATE(50, 1);
        CHECK_FALSE((negative << mad::cppin::in_ << collection));
    }
}
