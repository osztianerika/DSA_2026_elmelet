cmake_minimum_required(VERSION 4.1)
project(Het6 C)

set(CMAKE_C_STANDARD 23)

add_executable(Het6 main.c
        airport.c
        airport.h
        airportArray.c)
