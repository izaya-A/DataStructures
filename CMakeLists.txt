cmake_minimum_required(VERSION 3.0)

project(DATASTRUCTURES)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

add_executable(datastructures main.cpp)
include_directories(./)