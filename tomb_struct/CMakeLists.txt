cmake_minimum_required(VERSION 4.1)
project(tomb_struct C)

set(CMAKE_C_STANDARD 23)

add_executable(tomb_struct main.c
        functions_IntArray.c
        functions_IntArray.h)
