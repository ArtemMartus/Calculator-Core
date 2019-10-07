cmake_minimum_required(VERSION 3.15)
project(Core C)

set(CMAKE_C_STANDARD 11)


#add_library(Core library.c library.h)
add_library(Core SHARED source/Core.c publicHeaders/Core.h publicHeaders/types.h private/source/private.c private/headers/private.h private/headers/structures.h private/headers/defines.h private/headers/functions.h)

target_include_directories(Core PRIVATE private/headers publicHeaders)
set_target_properties(Core PROPERTIES PUBLIC_HEADER publicHeaders/Core.h)
