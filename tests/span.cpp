#include <array>
#include <span>
#include <type_traits>

#include <doctest/doctest.h>

#include <cppin/in.hpp>

TEST_CASE("check in_ for temporary std::span") {
    std::array<double, 4> arr = {3.0, 2.0, 7.0, 10.0};

    SUBCASE("positive") {
        auto two = 2.0 << mad::cppin::in_ << std::span<double>{arr};
        auto ten = 10.0 << mad::cppin::in_ << std::span<double>{arr};
        const std::span<double> view{arr};
        REQUIRE(two);
        CHECK(two == view.begin() + 1);
        REQUIRE(ten);
        CHECK(ten == view.begin() + 3);
    }

    SUBCASE("negative") {
        CHECK_FALSE((50.0 << mad::cppin::in_ << std::span<double>{arr}));
        CHECK_FALSE((1.0 << mad::cppin::in_ << std::span<double>{arr}));
    }

    static_assert(std::is_same_v<decltype((2.0 << mad::cppin::in_ << std::span<double>{arr})),
                                 std::optional<std::span<double>::iterator>>);
}
