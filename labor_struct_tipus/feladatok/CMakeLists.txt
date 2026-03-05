cmake_minimum_required(VERSION 4.1)
project(feladatok C)

set(CMAKE_C_STANDARD 23)

add_executable(feladatok main.c
        functions_struct.c
        functions_struct.h)
