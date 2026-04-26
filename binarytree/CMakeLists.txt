cmake_minimum_required(VERSION 4.1)
project(binarytree C)

set(CMAKE_C_STANDARD 23)

add_executable(binarytree main.c
        functions.c
        functions.h)
