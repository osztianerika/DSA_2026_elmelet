cmake_minimum_required(VERSION 4.1)
project(HashTable C)

set(CMAKE_C_STANDARD 23)

add_executable(HashTable main.c
        functions.c
        functions.h)
