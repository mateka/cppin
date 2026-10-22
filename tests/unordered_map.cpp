#include <string>
#include <unordered_map>

#include "dict_test.hpp"

TEST_CASE_TEMPLATE_INVOKE(dict_like_test_case, std::unordered_map<int, std::string>);
