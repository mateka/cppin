cmake_minimum_required(VERSION 3.25...4.4)

project(cppin VERSION 0.1.0 LANGUAGES CXX)

add_library(cppin INTERFACE)
target_compile_features(cppin INTERFACE cxx_std_26)
target_sources(
    cppin
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include
        FILES
            include/has_find.hpp
            include/in.hpp
            include/iterator_type.hpp
)


add_executable(cppin_test test/main.cpp)
target_link_libraries(cppin_test PRIVATE cppin)
