#pragma once
#include <iostream>
#include <vector>
#include "../StringUtils.h"

template<typename T> class Node
{
public:
    [[nodiscard]] virtual T evaluate() const = 0;
    [[nodiscard]] virtual std::string toString() const = 0;
    [[nodiscard]] virtual std::vector<Node<T>*> getVariables() const = 0;
    virtual ~Node() = default;
    [[nodiscard]] virtual Node<T>* clone() const = 0;
};

const std::string ADDITION = "+";
const std::string SUBTRACTION = "-";
const std::string MULTIPLICATION = "*";
const std::string DIVISION = "/";
const std::string SIN = "sin";
const std::string COS = "cos";