cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_COMPILER g++)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


project(lab_3)
message("Cmake is started")
add_executable(${PROJECT_NAME} EXCLUDE_FROM_ALL main.cpp)