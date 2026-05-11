cmake_minimum_required(VERSION 4.1)
project(hasitas_nevszerint C)

set(CMAKE_C_STANDARD 23)

add_executable(hasitas_nevszerint main.c functions_hash.h functions_hash.c)
