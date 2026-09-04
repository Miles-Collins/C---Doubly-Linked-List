cmake_minimum_required(VERSION 4.3)
project(CSC_340_02_Milestone_1___student)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CSC_340_02_Milestone_1___student
        dll_node.cpp
        dll_node.h
        doubly_linked_list.cpp
        doubly_linked_list.h
        json.hpp
        milestone1.cpp
        milestone1.h)

add_compile_options(-Wall -Wextra -Wpedantic)

add_compile_options(-fsanitize=address -g)
add_link_options(-fsanitize=address)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)