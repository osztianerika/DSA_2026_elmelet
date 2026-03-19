cmake_minimum_required(VERSION 4.1)
project(array_stack_queue C)

set(CMAKE_C_STANDARD 23)

add_executable(array_stack_queue main.c
        functions_array.c
        functions_array.h
        constants.h)
