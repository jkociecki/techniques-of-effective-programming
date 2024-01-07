cmake_minimum_required(VERSION 3.26)
project(lab05)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        lab05 main.cpp
        inclulde/CNodeHeaders/Node.h
        inclulde/CNodeHeaders/NodeOperatorOneArgument.h
        inclulde/CNodeHeaders/NodeOperatorTwoArguments.h
        inclulde/CNodeHeaders/NodeConstant.h
        inclulde/ExpressionTree.h
        inclulde/CNodeHeaders/NodeVariable.h
        inclulde/UI.h
        inclulde/UI.h
        inclulde/StringUtils.h
        src/StringUtils.cpp
        src/CNodeSource/NodeConstant.tpp
        src/CNodeSource/NodeOperatorOneArgument.tpp
        src/CNodeSource/NodeOperatorTwoArguments.tpp
        src/CNodeSource/NodeVariable.tpp
        src/ExpressionTree.tpp
        src/UI.tpp
        inclulde/SmartPointer.h
        inclulde/ReferenceCounter.h
        src/ReferenceCounter.cpp
)
