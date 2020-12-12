cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_COMPILER clang++10)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(MESSEGE "cmpilate cmake run")

project(lab_3_var_1)
message("Cmake is started")
add_executable(${PROJECT_NAME} EXCLUDE_FROM_ALL main.cpp)
target_sources(${PROJECT_NAME} PUBLIC person.cpp)