cmake_minimum_required(VERSION 4.1)
project(HashTable__1 C)

set(CMAKE_C_STANDARD 23)

add_executable(HashTable__1 main.c
        functions_hash.c
        functions_hash.h)
