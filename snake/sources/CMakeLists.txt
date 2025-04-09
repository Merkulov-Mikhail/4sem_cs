cmake_minimum_required(VERSION 3.10)

project(classes)

add_library(snake  STATIC snake.cc)
add_library(model  STATIC model.cc)
add_library(rabbit STATIC rabbit.cc)
add_library(view   STATIC view.cc model snake rabbit)
# add_library(Gview  STATIC Gview.cc )