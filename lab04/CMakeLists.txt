cmake_minimum_required(VERSION 3.26)
project(lab04)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        lab04 main.cpp
        inclulde/CNodeHeaders/CNode.h
        inclulde/CNodeHeaders/CNodeOneArguemnt.h
        src/CNodeSource/CNodeOneArgument.cpp
        inclulde/CNodeHeaders/CNodeTwoArguments.h
        src/CNodeSource/CNodeTwoArguments.cpp
        inclulde/CNodeHeaders/CLeaf.h
        src/CNodeSource/CLeaf.cpp
        inclulde/CTree.h
        src/CTree.cpp
        inclulde/CNodeHeaders/CVariable.h
        src/CNodeSource/CVariable.cpp
)
