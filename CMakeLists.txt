cmake_minimum_required(VERSION 3.18)
project(contest)

set(CMAKE_CXX_STANDARD 14)

add_definitions(-DLOCAL)

add_executable(contest main.cpp)
