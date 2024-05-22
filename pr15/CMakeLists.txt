cmake_minimum_required(VERSION 3.28)
project(pr15 C)

set(CMAKE_C_STANDARD 11)

add_executable(pr15 main.c
        student.c
        stack.c
        stack.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

