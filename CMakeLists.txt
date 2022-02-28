cmake_minimum_required(VERSION 3.21)
project(CSC340Asmt03)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(
        CSC340Asmt03
        src/Assignment-03_PA_TicTacToe.cpp
        #        src/Assignment-03_PB_CCNumberValidation.cpp
        #        src/Assignment-03_PC_Dictionary.cpp
)
