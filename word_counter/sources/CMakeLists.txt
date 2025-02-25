cmake_minimum_required(VERSION 3.10)


project(container)


add_library(parser STATIC parser.c)
add_library(container STATIC container.c)
# add_library(algorithm STATIC algorithm.c)