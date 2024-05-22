cmake_minimum_required(VERSION 3.28)
project(pr16 C)

include(CTest)
enable_testing()

add_executable(pr16 main.c
        student.c
        stack.c
        stack.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

