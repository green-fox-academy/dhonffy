cmake_minimum_required(VERSION 3.14)
project(sandw C)

set(CMAKE_C_STANDARD 11)

add_executable(sandw main.c order_sandwiches.h order_sandwiches.c)