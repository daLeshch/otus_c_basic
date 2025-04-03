cmake_minimum_required(VERSION 3.7.2)
project(hw9 CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(hw9 top_words.cpp)

if (MSVC)
    target_compile_options(hw9 PUBLIC /W4)
else ()
    target_compile_options(hw9 PUBLIC -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion)
endif ()