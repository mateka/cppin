#include <type_traits>
#include <utility>

#include <doctest/doctest.h>

#include <cppin/in.hpp>

TEST_CASE_TEMPLATE_DEFINE("check list-like cases", TList, list_like_test_case) {
    TList collection = TList{3, 2, 7, 10};
    SUBCASE("present") {
        auto positive = GENERATE(std::pair{2, 1}, std::pair{10, 3});
        auto positive_result = positive.first << mad::cppin::in_ << collection;
        REQUIRE(positive_result);
        auto result_index = std::distance(std::cbegin(collection), *positive_result);
        CHECK(positive.second == result_index);
    }

    SUBCASE("absent") {
        auto negative = GENERATE(50, 1);
        CHECK_FALSE((negative << mad::cppin::in_ << collection));
    }

    SUBCASE("Test in result cast to bool with temporary collection") {
        auto result = static_cast<bool>(1 << mad::cppin::in_ << TList{1});
        CHECK(result);
    }

    static_assert(std::is_same_v<decltype((2 << mad::cppin::in_ << collection)),
                                 std::optional<decltype(std::cbegin(collection))>>);
    static_assert(std::is_same_v<decltype((2 << mad::cppin::in_ << TList{2})),
                                 std::optional<std::ranges::dangling>>);
}
