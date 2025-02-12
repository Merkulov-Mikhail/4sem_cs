cmake_minimum_required(VERSION 3.10)

project(main)

include_directories(include)

add_subdirectory(sources)
add_executable(main main.c)
target_link_libraries(main dog cat animal)
