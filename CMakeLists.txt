cmake_minimum_required(VERSION 3.25)
project(Rock_Paper_Scissors C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Rock_Paper_Scissors
        main.c
        main.h)
