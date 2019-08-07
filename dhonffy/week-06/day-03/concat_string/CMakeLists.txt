cmake_minimum_required(VERSION 3.14)
project(concat_string C)

set(CMAKE_C_STANDARD 11)

add_executable(concat_string main.c concat_string.h concat_string.c)