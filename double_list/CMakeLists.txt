cmake_minimum_required(VERSION 4.1)
project(duble_list C)

set(CMAKE_C_STANDARD 23)

add_executable(duble_list main.c
        functions.c
        functions.h)
