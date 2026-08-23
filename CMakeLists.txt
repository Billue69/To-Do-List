cmake_minimum_required(VERSION 3.10.0)
project(toDoList VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(toDoList main.cpp tasks.h tasks.cpp terminal.cpp terminal.h)

