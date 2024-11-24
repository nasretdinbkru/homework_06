cmake_minimum_required( VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)

project(containers CXX)


add_library(linkedlist STATIC linkedlist.h)
add_library(dynarray STATIC dynarray.h)

set_target_properties(linkedlist PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(dynarray PROPERTIES LINKER_LANGUAGE CXX)

add_executable(containers main.cpp
        dynarray.h
)

target_link_libraries(containers PRIVATE linkedlist)
target_link_libraries(containers PRIVATE dynarray)

