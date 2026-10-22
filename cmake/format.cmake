# Targets `format` (formats files in place) and `format-check` (fails on unformatted files).
# Set CLANG_FORMAT_EXE (e.g. in CMakeUserPresets.json) when clang-format is not in PATH.
find_program(
    CLANG_FORMAT_EXE
    NAMES clang-format
)

if(NOT CLANG_FORMAT_EXE)
  message(STATUS "clang-format not found, format targets disabled")
  return()
endif()

file(
    GLOB_RECURSE CPPIN_FORMAT_FILES
    CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/include/*.hpp"
    "${PROJECT_SOURCE_DIR}/tests/*.cpp"
    "${PROJECT_SOURCE_DIR}/tests/*.hpp"
)

add_custom_target(
    format
    COMMAND "${CLANG_FORMAT_EXE}" -i ${CPPIN_FORMAT_FILES}
    COMMENT "Formatting sources with clang-format"
    VERBATIM
)

add_custom_target(
    format-check
    COMMAND "${CLANG_FORMAT_EXE}" --dry-run --Werror ${CPPIN_FORMAT_FILES}
    COMMENT "Checking formatting with clang-format"
    VERBATIM
)
