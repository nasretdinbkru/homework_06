cmake_minimum_required( VERSION 3.2)
set(CMAKE_CXX_STANDARD 17)

project(containers)

add_library(linkedlist INTERFACE)
add_executable(containers main.cpp
        linkedlist.h)
