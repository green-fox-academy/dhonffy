cmake_minimum_required(VERSION 3.14)
project(greenFoxInharitanceExcercise)

set(CMAKE_CXX_STANDARD 14)

add_executable(greenFoxInharitanceExcercise main.cpp Person.cpp Person.h Student.cpp Student.h Mentor.cpp Mentor.h Sponsor.cpp Sponsor.h Cohort.cpp Cohort.h)