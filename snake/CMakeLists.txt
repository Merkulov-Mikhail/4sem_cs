cmake_minimum_required(VERSION 3.10)

project(snake)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

include_directories(include)
add_subdirectory(sources)
add_executable(main main.cc)

target_compile_options(main PRIVATE -g)

target_link_libraries(main PRIVATE snake model rabbit view)

