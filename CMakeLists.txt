cmake_minimum_required(VERSION 3.16)

project(Sudoku
        LANGUAGES CXX)

add_executable(sudoku main.cpp src/Sudoku_functions.cpp)
target_include_directories(sudoku PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
