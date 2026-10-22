#include <unordered_set>

#include "set_test.hpp"


TEST_CASE_TEMPLATE_INVOKE(set_like_test_case, std::unordered_set<int>);
