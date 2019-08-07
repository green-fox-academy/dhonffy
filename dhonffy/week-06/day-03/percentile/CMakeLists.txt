cmake_minimum_required(VERSION 3.14)
project(percentile C)

set(CMAKE_C_STANDARD 11)

add_executable(percentile main.c read_size.h read_size.c ask_value.h ask_value.c)