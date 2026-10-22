#include <doctest/doctest.h>
#include <cppin/in.hpp>


TEST_CASE_TEMPLATE_DEFINE("check set-like cases", TSet, set_like_test_case) {
    TSet collection = TSet{ 3, 2, 7, 10 };
    SUBCASE("present") {
        auto positive = GENERATE(2, 10);
        auto positive_result = positive << mad::cppin::in_ << collection;
        REQUIRE(positive_result);
        CHECK(*positive_result.position() == positive);
    }

    SUBCASE("absent") {
        auto negative = GENERATE(50, 1);
        CHECK_FALSE((negative << mad::cppin::in_ << collection));
    }
}
