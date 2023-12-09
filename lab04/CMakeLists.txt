cmake_minimum_required(VERSION 3.26)
project(lab04)

set(CMAKE_CXX_STANDARD 17)

add_executable(teplab03final main.cpp
        include/ExpressionTreeHeaders/ExpressionTree.h
        src/ExpressionTreeSrc/ExpressionTree.cpp
        src/ExpressionTreeSrc/Node.cpp
        src/StringUtils.cpp
        include/UI.h
        src/UI.cpp
)
