#include "Node.h"
#include <iostream>
#pragma once


template<typename T>
class NodeVariable : public Node<T>
{
private:
    std::string name;
    T value;

    NodeVariable(std::string name, T value) : name(name), value(value) {};
    NodeVariable(const NodeVariable& other) : name(other.name), value(other.value) {};
    NodeVariable(NodeVariable&& other) : name(other.name), value(other.value) {};
    ~NodeVariable() override = default;

    [[nodiscard]] T evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] std::vector<Node<T>*> getVariables() const override;
    [[nodiscard]] NodeVariable* clone() const override;
    template<typename> friend class ExpressionTree;
};


#include "../../src/CNodeSource/NodeVariable.tpp"