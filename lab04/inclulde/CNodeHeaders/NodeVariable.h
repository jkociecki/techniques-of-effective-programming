#include "Node.h"
#include <iostream>
#pragma once

class NodeVariable : public Node
{
private:
    std::string name;
    double value;
    [[nodiscard]] double evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    NodeVariable(std::string name, double value) : name(name), value(value) {};
    NodeVariable(const NodeVariable& other) : name(other.name), value(other.value) {};
    [[nodiscard]] NodeVariable* clone() const override;
    [[nodiscard]] std::vector<Node*> getVariables() const override;
    ~NodeVariable() override = default;


    friend class ExpressionTree;
};


