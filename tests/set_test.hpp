#include <type_traits>

#include <doctest/doctest.h>

#include <cppin/in.hpp>

TEST_CASE_TEMPLATE_DEFINE("check set-like cases", TSet, set_like_test_case) {
    TSet collection = TSet{3, 2, 7, 10};
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

    SUBCASE("Test in result cast to bool with temporary collection") {
        auto result = static_cast<bool>(1 << mad::cppin::in_ << TSet{1});
        CHECK(result);
    }

    static_assert(std::is_same_v<decltype((2 << mad::cppin::in_ << collection).position()),
                                 decltype(std::cbegin(collection))>);
    static_assert(std::is_same_v<decltype((2 << mad::cppin::in_ << TSet{2}).position()),
                                 std::ranges::dangling>);
}
