cmake_minimum_required(VERSION 3.14)
project(circilar_linked_list C)

set(CMAKE_C_STANDARD 11)

add_executable(linked_list main.c circular_linked_list.h circular_linked_list.c)