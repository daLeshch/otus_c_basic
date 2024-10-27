cmake_minimum_required(VERSION 3.12)

project(number_guess)

add_executable(number_guess
    main.cpp
)

set_target_properties(number_guess PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)