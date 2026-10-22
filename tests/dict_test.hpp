#include <type_traits>
#include <utility>

#include <doctest/doctest.h>

#include <cppin/in.hpp>

TEST_CASE_TEMPLATE_DEFINE("check dict-like cases", TDict, dict_like_test_case) {
    TDict collection = TDict{{3, "three"}, {2, "two"}, {7, "seven"}, {10, "ten"}};

    SUBCASE("present") {
        auto positive = GENERATE(std::pair{2, "two"}, std::pair{10, "ten"});
        auto positive_result = positive.first << mad::cppin::in_ << collection;
        REQUIRE(positive_result);
        CHECK((*positive_result)->first == positive.first);
        CHECK((*positive_result)->second == positive.second);
    }

    SUBCASE("absent") {
        auto negative = GENERATE(50, 1);
        CHECK_FALSE((negative << mad::cppin::in_ << collection));
    }

    SUBCASE("Test in result cast to bool with temporary collection") {
        auto result = static_cast<bool>(1 << mad::cppin::in_ << TDict{{1, "one"}});
        CHECK(result);
    }

    static_assert(std::is_same_v<decltype((2 << mad::cppin::in_ << collection)),
                                 std::optional<decltype(std::cbegin(collection))>>);
    static_assert(std::is_same_v<decltype((2 << mad::cppin::in_ << TDict{{2, "two"}})),
                                 std::optional<std::ranges::dangling>>);
}
