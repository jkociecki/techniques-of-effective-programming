#include "Node.h"
#include <iostream>
#include <string>
#include <cmath>
#include <utility>
#pragma once



template<typename T>
class NodeOperatorOneArgument : public Node<T>
{
private:
    Node<T>* child;
    std::string operatation;

    NodeOperatorOneArgument(std::string op, Node<T>* child)
        : operatation(std::move(op)), child(child) {};
    NodeOperatorOneArgument(const NodeOperatorOneArgument& other)
        : operatation(other.operatation), child(other.child->clone()) {};
    NodeOperatorOneArgument(NodeOperatorOneArgument&& other) noexcept;
    ~NodeOperatorOneArgument() override;

    [[nodiscard]] T evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] std::vector<Node<T>*> getVariables() const override;
    [[nodiscard]] NodeOperatorOneArgument* clone() const override;
    template<typename> friend class ExpressionTree;
};


#include "../StringUtils.h"

template<typename T>
NodeOperatorOneArgument<T>::NodeOperatorOneArgument(NodeOperatorOneArgument&& other) noexcept
{
    operatation = std::move(other.operatation);
    child = other.child;
    other.child = nullptr;
}


template<typename T>
std::vector<Node<T>*> NodeOperatorOneArgument<T>::getVariables() const
{
    return std::vector<Node<T> *>() = {child};
}

template<typename T>
T NodeOperatorOneArgument<T>::evaluate() const
{
    T child_value = child->evaluate();
    if(operatation == SIN) return sin(child_value);
    if(operatation == COS) return cos(child_value);
    return 0;
}

template<typename T>
std::string NodeOperatorOneArgument<T>::toString() const
{
    return operatation;
}

template<typename T>
NodeOperatorOneArgument<T>::~NodeOperatorOneArgument()
{
    delete child;
}

template<typename T>
NodeOperatorOneArgument<T>* NodeOperatorOneArgument<T>::clone() const
{
    return new NodeOperatorOneArgument(*this);
}

template<>
std::string NodeOperatorOneArgument<std::string>::evaluate() const
{
    std::string child_value = child->evaluate();
    if(operatation == SIN) return toUpper(child_value);
    if(operatation == COS) return toLower(child_value);
    return "";
}