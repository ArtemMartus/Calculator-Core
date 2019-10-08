cmake_minimum_required(VERSION 3.15)
project(Core)


#add_library(Core library.c library.h)
add_library(Core SHARED public/source/Core.c public/headers/Core.h public/headers/types.h private/source/private.c private/headers/private.h private/headers/structures.h private/headers/defines.h private/headers/functions.h)
set_property(TARGET Core PROPERTY CXX_STANDARD 11)
set_property(TARGET Core PROPERTY CXX_STANDARD_REQUIRED ON)
target_include_directories(Core PRIVATE private/headers public/headers)
set_target_properties(Core PROPERTIES PUBLIC_HEADER public/headers/Core.h)
