cmake_minimum_required(VERSION 3.10)

include_directories(include)
add_subdirectory(sources)

add_executable(main main.c)
target_link_libraries(main PRIVATE container parser)#  algorithm)