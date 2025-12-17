cmake_minimum_required(VERSION 3.10)
project(extracd1_oop C)

set(CMAKE_C_STANDARD 99)

add_executable(extracd1_oop
        main.c
        menu.c menu.h
        distribution.c distribution.h
        histogram.c histogram.h
        distance.c distance.h
        cipher.c cipher.h
)
