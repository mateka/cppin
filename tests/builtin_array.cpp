#include <type_traits>

#include <doctest/doctest.h>

#include <cppin/in.hpp>

TEST_CASE("check in_ for builtin array") {
    float array[] = {3.0f, 2.0f, 7.0f, 10.0f};  // NOLINT(modernize-avoid-c-arrays)
    SUBCASE("positive") {
        auto two = 2.0f << mad::cppin::in_ << array;
        auto ten = 10.0f << mad::cppin::in_ << array;
        CHECK(two);
        CHECK(two.position() == &(array[1]));
        CHECK(ten);
        CHECK(ten.position() == &(array[3]));
    }

    SUBCASE("negative") {
        CHECK_FALSE((50.0f << mad::cppin::in_ << array));
        CHECK_FALSE((1.0f << mad::cppin::in_ << array));
    }

    using float_array_t = float[4];  // NOLINT(modernize-avoid-c-arrays)
    SUBCASE("Test in result cast to bool with temporary") {
        auto result = static_cast<bool>(1.0f << mad::cppin::in_ << float_array_t{1.0f});
        CHECK(result);
    }

    static_assert(std::is_same_v<decltype((2.0f << mad::cppin::in_ << array).position()),
                                 decltype(std::cbegin(array))>);
    static_assert(
        std::is_same_v<decltype((2.0f << mad::cppin::in_ << float_array_t{2.0f}).position()),
                       std::ranges::dangling>);
}
