#include <utility>

#include <doctest/doctest.h>
#include <cppin/in.hpp>


TEST_CASE_TEMPLATE_DEFINE("check list-like cases", TList, list_like_test_case) {
    TList collection = TList{ 3, 2, 7, 10 };
    SUBCASE("present") {
        auto positive = GENERATE(std::pair{2, 1}, std::pair{10, 3});
        auto positive_result = positive.first << mad::cppin::in_ << collection;
        REQUIRE(positive_result);
        auto result_index = std::distance(std::cbegin(collection), positive_result.position());
        CHECK(positive.second == result_index);
    }

    SUBCASE("absent") {
        auto negative = GENERATE(50, 1);
        CHECK_FALSE((negative << mad::cppin::in_ << collection));
    }
}
