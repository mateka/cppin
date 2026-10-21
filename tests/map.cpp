#include "dict_test.hpp"
#include <map>
#include <string>


TEST_CASE_TEMPLATE_INVOKE(test_id, std::map<int, std::string>);
