#include "Node.h"
#include <iostream>
#pragma once


template<typename T>
class NodeVariable : public Node<T>
{
private:
    std::string name;
    T value;
    [[nodiscard]] T evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    NodeVariable(std::string name, T value) : name(name), value(value) {};
    NodeVariable(const NodeVariable& other) : name(other.name), value(other.value) {};
    [[nodiscard]] std::vector<Node<T>*> getVariables() const override;
    ~NodeVariable() override = default;
    [[nodiscard]] NodeVariable* clone() const override;
    template<typename> friend class ExpressionTree;

};


#include "../../src/CNodeSource/NodeVariable.tpp"