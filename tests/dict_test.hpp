#include <doctest/doctest.h>
#include <cppin/in.hpp>


TEST_CASE_TEMPLATE_DEFINE("check list-like cases", TDict, test_id) {
    TDict collection = TDict{ { 3, "three" }, { 2, "two" }, { 7, "seven" }, { 10, "ten" } };
    auto positive = GENERATE(2, 10);
    auto negative = GENERATE(50, 1);
    CHECK((positive << mad::cppin::in_ << collection));
    CHECK_FALSE((negative << mad::cppin::in_ << collection));
}
