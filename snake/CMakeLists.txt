cmake_minimum_required(VERSION 3.10)

project(snake)

include_directories(include)
add_subdirectory(sources)
add_executable(main main.cc)

target_link_libraries(main PRIVATE snake)