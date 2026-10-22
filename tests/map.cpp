#include <map>
#include <string>

#include "dict_test.hpp"

TEST_CASE_TEMPLATE_INVOKE(dict_like_test_case, std::map<int, std::string>);
