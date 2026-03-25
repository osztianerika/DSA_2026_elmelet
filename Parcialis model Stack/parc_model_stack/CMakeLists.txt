cmake_minimum_required(VERSION 4.1)
project(parc_model_stack C)

set(CMAKE_C_STANDARD 23)

add_executable(parc_model_stack main.c
        function.c
        function.h)
