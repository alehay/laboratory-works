cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_COMPILER g++)

add_compile_options(-Werror)
add_compile_options(-pedantic-errors)
add_compile_options(-Wall)
add_compile_options(-Wextra)
#add_compile_options(-O2)
#add_compile_options(-fsanitize=address)
#add_compile_options(-Wcast-align)
#add_compile_options(-Wcast-qual)
#add_compile_options(-Wconversion)
#add_compile_options(-Wctor-dtor-privacy)
#add_compile_options(-Wduplicated-branches)
#add_compile_options(-Wduplicated-cond)
#add_compile_options(-Wextra-semi)
#add_compile_options(-Wfloat-equal)
#add_compile_options(-Wlogical-op)
#add_compile_options(-Wnon-virtual-dtor)
#add_compile_options(-Wold-style-cast)
#add_compile_options(-Woverloaded-virtual)
#add_compile_options(-Wredundant-decls)
#add_compile_options(-Wsign-conversion)
#add_compile_options(-Wsign-promo)
#add_compile_options(-lasan)



set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(MESSEGE "cmpilate cmake run")

project(lab)
message("Cmake is started")
add_executable(${PROJECT_NAME} EXCLUDE_FROM_ALL main.cpp)
