cmake_minimum_required(VERSION 3.10)

project(07.homework)

if (MSVC)
    # @see https://github.com/google/googletest/blob/master/googletest/README.md
    # Visual Studio Dynamic vs Static Runtimes
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()
# Build googletest
add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/build/googletest" 
    "googletest"
)

# Main target
add_executable(
    containers
    seqContainer.cpp
    seqContainer.h
    dl_list.cpp
    dl_list.h
)

# Test target
add_executable(
    containers_tests
    test/seqContainer_tests.cpp
    test/dl_list_tests.cpp
)

# Add src to the include directories for the test target
target_include_directories(
    containers_tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# Link test target against gtest libraries
target_link_libraries(
    containers_tests PRIVATE
    gtest gtest_main
)

set_target_properties(containers PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(containers_tests PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (MSVC)
    target_compile_options(
        containers PRIVATE
        /W4
    )
    target_compile_options(
        containers_tests PRIVATE
        /W4
    )
else ()
    target_compile_options(
        containers PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(
        containers_tests PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()
