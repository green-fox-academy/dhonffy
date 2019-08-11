cmake_minimum_required(VERSION 3.14)
project(look_for_maximum C)

set(CMAKE_C_STANDARD 11)

add_executable(look_for_maximum main.c read_size.c read_size.h)