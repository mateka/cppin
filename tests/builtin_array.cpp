#include <doctest/doctest.h>
#include <cppin/in.hpp>


TEST_CASE("check in_ for builtin array") {
    float array[] = { 3.0f, 2.0f, 7.0f, 10.0f };
    CHECK((2.0f << mad::cppin::in_ << array));
    CHECK((10.0f << mad::cppin::in_ << array));
    CHECK_FALSE((50.0f << mad::cppin::in_ << array));
    CHECK_FALSE((1.0f << mad::cppin::in_ << array));
}
