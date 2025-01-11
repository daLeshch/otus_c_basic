cmake_minimum_required(VERSION 3.10)
project(07.homework)

# Добавление Google Test как подмодуля
add_subdirectory(googletest)

# Укажите файлы исходного кода
add_executable(containers_tests seqContainer_tests.cpp seqContainer.cpp)

# Привязка к библиотеке Google Test
target_link_libraries(containers_tests gtest gtest_main pthread)
