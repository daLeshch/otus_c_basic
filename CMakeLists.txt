cmake_minimum_required(VERSION 3.7.2)
project(hw9 CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(hw9 top_words.cpp)

set_target_properties(hw9 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)