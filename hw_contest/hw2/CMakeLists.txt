cmake_minimum_required(VERSION 3.10)
project(hw2)

set(PROBLEMS matrix_sort store_room az_count)

foreach (PROBLEM ${PROBLEMS})
    add_executable(${PROBLEM} ${PROBLEM}.cc)
    target_compile_options(${PROBLEM} INTERFACE "-g -Wall -Wextra")
endforeach()
