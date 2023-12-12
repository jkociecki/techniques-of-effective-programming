cmake_minimum_required(VERSION 3.26)
project(lab03dziedzic)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        lab03dziedzic main.cpp
        inclulde/CNode.h
        inclulde/CNodeOneArguemnt.h
        src/CNodeOneArgument.cpp
        inclulde/CNodeTwoArguments.h
        src/CNodeTwoArguments.cpp
        inclulde/CLeaf.h
        src/CLeaf.cpp
        inclulde/CTree.h
        src/CTree.cpp
        inclulde/CVariable.h
        src/CVariable.cpp
)
