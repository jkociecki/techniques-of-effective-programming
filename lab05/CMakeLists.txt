cmake_minimum_required(VERSION 3.26)
project(lab05)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        lab05 main.cpp
        include/ExpressionTree/Node.h
        include/ExpressionTree/NodeOperatorOneArgument.h
        include/ExpressionTree/NodeOperatorTwoArguments.h
        include/ExpressionTree/NodeConstant.h
        include/ExpressionTree/ExpressionTree.h
        include/ExpressionTree/NodeVariable.h
        include/UI.h
        include/UI.h
        include/StringUtils.h
        src/StringUtils.cpp
        include/ExpressionTree/ExpressionTree.tpp
        include/UI.tpp
        my-pointer/SmartPointer.h
        my-pointer/ReferenceCounter.h
        my-pointer/ReferenceCounter.cpp
        my-pointer/ReferenceCounter.cpp
        my-pointer/MyArray.h
        my-pointer/MyArray2.h
)
