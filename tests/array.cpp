#include <array>

#include "list_test.hpp"

TEST_CASE_TEMPLATE_INVOKE(list_like_test_case, std::array<int, 4>);
