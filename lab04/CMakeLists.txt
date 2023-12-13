cmake_minimum_required(VERSION 3.26)
project(lab04)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        lab04 main.cpp
        inclulde/CNodeHeaders/Node.h
        inclulde/CNodeHeaders/NodeOperatorOneArgument.h
        src/CNodeSource/CNodeOneArgument.cpp
        inclulde/CNodeHeaders/NodeOperatorTwoArguments.h
        src/CNodeSource/NodeOperatorTwoArguments.cpp
        inclulde/CNodeHeaders/NodeConstant.h
        src/CNodeSource/NodeConstant.cpp
        inclulde/ExpressionTree.h
        src/ExpressionTree.cpp
        inclulde/CNodeHeaders/NodeVariable.h
        src/CNodeSource/NodeVariable.cpp
        src/UI.cpp
        inclulde/UI.h
        inclulde/UI.h
        inclulde/StringUtils.h
        src/StringUtils.cpp
        src/UI.cpp
        src/ExpressionTree.cpp
        src/CNodeSource/NodeConstant.cpp
        src/CNodeSource/NodeOperatorTwoArguments.cpp
)
