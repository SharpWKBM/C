cmake_minimum_required(VERSION 3.28)
project(pr14 C)

set(CMAKE_C_STANDARD 11)

add_executable(pr14 main.c student.c stack.c
        stack.c)
