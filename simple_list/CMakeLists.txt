cmake_minimum_required(VERSION 4.1)
project(simple_list C)

set(CMAKE_C_STANDARD 23)

add_executable(simple_list main.c
        functions_simple_list.c
        functions_simple_list.h)
