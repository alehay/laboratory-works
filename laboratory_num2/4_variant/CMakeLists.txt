cmake_minimum_required(VERSION 3.0.0)

project(lab2_4var VERSION 0.1.0)

include(CTest)
#enable_testing()

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)


add_executable(${PROJECT_NAME} main.cpp)
#target_sources(${PROJECT_NAME} PRIVATE mymatrix.cpp)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
