cmake_minimum_required(VERSION 3.5)

project(06.homework)

add_executable(containers dl_list.cpp dl_list.h sl_list.cpp sl_list.h main.cpp)
set_target_properties(containers PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

# Добавляем цель для запускa
add_custom_target(run
    COMMAND containers
    DEPENDS containers
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)