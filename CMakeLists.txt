cmake_minimum_required(VERSION 3.16)
project(Ex2b)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Ex2b
    Demo.cpp
    doctest.h
    FamilyTree.cpp
    FamilyTree.hpp
    grade
    grade_utils
    LICENSE
    Makefile
    README.md
    Test1.cpp
    Test2.cpp
    Test_ariel.cpp
    Test_hila.cpp
    TestRunner.cpp)
