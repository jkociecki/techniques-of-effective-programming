#include "Node.h"
#include <iostream>
#include <utility>
#pragma once


template<typename T>
class NodeVariable : public Node<T>
{
private:
    std::string name;
    T value;

    NodeVariable(std::string name, T value) : name(std::move(name)), value(value) {};
    NodeVariable(const NodeVariable& other) : name(other.name), value(other.value) {};
    NodeVariable(NodeVariable&& other) noexcept : name(std::move(other.name)), value(other.value) {};
    ~NodeVariable() override = default;

    [[nodiscard]] T evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] std::vector<Node<T>*> getVariables() const override;
    [[nodiscard]] NodeVariable* clone() const override;
    template<typename> friend class ExpressionTree;
};


template<typename T>
T NodeVariable<T>::evaluate() const
{
    return value;
}

template<typename T>
std::string NodeVariable<T>::toString() const
{
    return name;
}

template<typename T>
std::vector<Node<T>*> NodeVariable<T>::getVariables() const
{
    return std::vector<Node<T>*>();
}


template<typename T>
NodeVariable<T>* NodeVariable<T>::clone() const
{
    return new NodeVariable(*this);
}