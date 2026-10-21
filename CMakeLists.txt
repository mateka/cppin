cmake_minimum_required(VERSION 3.25...4.4)

project(cppin VERSION 0.1.0 LANGUAGES CXX)

option(CPPIN_BUILD_TESTS "Build cppin tests" ${PROJECT_IS_TOP_LEVEL})


add_library(cppin INTERFACE)
add_library(cppin::cppin ALIAS cppin)

target_compile_features(cppin INTERFACE cxx_std_26)
target_sources(
    cppin
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include
        FILES
            include/cppin/has_find.hpp
            include/cppin/in.hpp
            include/cppin/iterator_type.hpp
)


if(CPPIN_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
