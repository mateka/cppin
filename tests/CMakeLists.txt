include(FetchContent)
FetchContent_Declare(doctest
  GIT_REPOSITORY https://github.com/doctest/doctest.git
  GIT_TAG        v2.5.3
  GIT_SHALLOW    TRUE
  FIND_PACKAGE_ARGS 2.5)
FetchContent_MakeAvailable(doctest)

add_executable(
    cppin_tests
    vector.cpp
    list.cpp
    array.cpp
    builtin_array.cpp
    set.cpp
    unordered_set.cpp
    map.cpp
    unordered_map.cpp
)
target_link_libraries(cppin_tests PRIVATE cppin::cppin doctest::doctest_with_main)

include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
doctest_discover_tests(cppin_tests)
