cmake_minimum_required(VERSION 4.1)
project(stack_queue C)

set(CMAKE_C_STANDARD 23)

add_executable(stack_queue main.c
        functions_stack.c
        functions_stack.h
        functions_queue.c
        functions_queue.h)
