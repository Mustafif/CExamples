cmake_minimum_required(VERSION 3.25)
project(examples C)

set(CMAKE_C_STANDARD 11)

add_executable(examples main.c array.h array.c)
