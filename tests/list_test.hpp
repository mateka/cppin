#include <doctest/doctest.h>
#include <cppin/in.hpp>


TEST_CASE_TEMPLATE_DEFINE("check list-like cases", TList, test_id) {
    TList collection = TList{ 3, 2, 7, 10 };
    auto positive = GENERATE(2, 10);
    auto negative = GENERATE(50, 1);
    CHECK((positive << mad::cppin::in_ << collection));
    CHECK_FALSE((negative << mad::cppin::in_ << collection));
}
