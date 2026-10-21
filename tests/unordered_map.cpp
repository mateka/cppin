#include "dict_test.hpp"
#include <unordered_map>
#include <string>


TEST_CASE_TEMPLATE_INVOKE(test_id, std::unordered_map<int, std::string>);
