cmake_minimum_required(VERSION 3.26)
project(lab02f)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab02f main.cpp
        src/CNumber/CNumberMathOperations.cpp
        src/CNumber/CNumber.cpp
        include/CNumber.h
        src/CNumber/CNumberOperators.cpp
)
