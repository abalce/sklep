cmake_minimum_required(VERSION 3.27)
project(sklep)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(sklep
        main.cpp
        sklepik.h)
