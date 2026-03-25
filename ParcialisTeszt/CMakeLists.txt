cmake_minimum_required(VERSION 4.0)
project(ParcialisTeszt C)

set(CMAKE_C_STANDARD 23)

add_executable(ParcialisTeszt main.c
        functions.c
        functions.h
        functions_stack.c)
