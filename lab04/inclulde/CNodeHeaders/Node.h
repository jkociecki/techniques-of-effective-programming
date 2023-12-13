#pragma once
#include <iostream>
#include <vector>

class Node
{
public:
    [[nodiscard]] virtual double evaluate() const = 0;
    [[nodiscard]] virtual std::string toString() const = 0;
    [[nodiscard]] virtual std::vector<Node*> getVariables() const = 0;
    [[nodiscard]] virtual Node* clone() const = 0;
    virtual ~Node() = default;
};

const std::string ADDITION = "+";
const std::string SUBTRACTION = "-";
const std::string MULTIPLICATION = "*";
const std::string DIVISION = "/";
const std::string SIN = "sin";
const std::string COS = "cos";

