cmake_minimum_required(VERSION 3.26)
project(lab04)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        lab04test main.cpp
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
        inclulde/CNodeTPP/NodeConstant.tpp
        inclulde/CNodeTPP/NodeOperatorOneArgument.tpp
        inclulde/CNodeTPP/NodeOperatorTwoArguments.tpp
        inclulde/CNodeTPP/NodeVariable.tpp
        inclulde/CNodeTPP/ExpressionTree.tpp
        inclulde/UI.tpp
        src/CNodeSource/Nodes.cpp
        src/CNodeSource/ExpressionTree.cpp
)
