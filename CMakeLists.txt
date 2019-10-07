cmake_minimum_required(VERSION 3.15)
project(Core C)

set(CMAKE_C_STANDARD 11)

#add_library(Core library.c library.h)
add_library(Core SHARED library.c library.h)

set_target_properties(Core PROPERTIES PUBLIC_HEADER library.h)
