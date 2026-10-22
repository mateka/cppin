include(FetchContent)
FetchContent_Declare(doctest
  GIT_REPOSITORY https://github.com/doctest/doctest.git
  GIT_TAG        v2.5.3
  GIT_SHALLOW    TRUE
  FIND_PACKAGE_ARGS 2.5)
FetchContent_MakeAvailable(doctest)
include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)

set(
    CPPIN_TEST_SOURCES
        example_2.cpp
        vector.cpp
        list.cpp
        array.cpp
        builtin_array.cpp
        set.cpp
        unordered_set.cpp
        map.cpp
        unordered_map.cpp
)

foreach(variant IN ITEMS macro no_macro)
  add_executable(cppin_tests_${variant} ${CPPIN_TEST_SOURCES})
  target_link_libraries(cppin_tests_${variant} PRIVATE cppin::cppin doctest::doctest_with_main)
  doctest_discover_tests(cppin_tests_${variant} TEST_SUFFIX " [${variant}]")
endforeach()

target_sources(cppin_tests_macro PRIVATE macro.cpp)
target_compile_definitions(cppin_tests_no_macro PRIVATE NO_IN_MACRO)
