cmake_minimum_required(VERSION 3.26)
project(lab05)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        lab05 main.cpp
        inclulde/ExpressionTree/Node.h
        inclulde/ExpressionTree/NodeOperatorOneArgument.h
        inclulde/ExpressionTree/NodeOperatorTwoArguments.h
        inclulde/ExpressionTree/NodeConstant.h
        inclulde/ExpressionTree/ExpressionTree.h
        inclulde/ExpressionTree/NodeVariable.h
        inclulde/UI.h
        inclulde/UI.h
        inclulde/StringUtils.h
        src/StringUtils.cpp
        inclulde/ExpressionTree/ExpressionTree.tpp
        inclulde/UI.tpp
        my-pointer/SmartPointer.h
        my-pointer/ReferenceCounter.h
        my-pointer/ReferenceCounter.cpp
        my-pointer/ReferenceCounter.cpp
)
