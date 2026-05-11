cmake_minimum_required(VERSION 4.1)
project(hasitas_lancolassal C)

set(CMAKE_C_STANDARD 23)

add_executable(hasitas_lancolassal main.c
        functions.c
        functions.h
        node.c
        node.h)
