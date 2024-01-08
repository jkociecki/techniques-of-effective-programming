#include <iostream>
#include <utility>
#include "Node.h"
#pragma once

template<typename T>
class NodeOperatorTwoArguments : public Node<T>
{
private:
    Node<T>* left;
    Node<T>* right;
    std::string operatation;

    NodeOperatorTwoArguments(std::string op, Node<T>* left, Node<T>* right)
        : operatation(std::move(op)), left(left), right(right) {};
    NodeOperatorTwoArguments(const NodeOperatorTwoArguments& other)
            : operatation(other.operatation), left(other.left->clone()), right(other.right->clone()) {};
    ~NodeOperatorTwoArguments() override;


    [[nodiscard]] T evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] NodeOperatorTwoArguments* clone() const override;
    [[nodiscard]] std::vector<Node<T>*> getVariables() const override;
    template<typename> friend class ExpressionTree;
};

#include "../StringUtils.h"

template<typename T>
T NodeOperatorTwoArguments<T>::evaluate() const
{
    T left_value = left->evaluate();
    T right_value = right->evaluate();
    if (operatation == ADDITION) return left_value + right_value;
    if (operatation == SUBTRACTION) return left_value - right_value;
    if (operatation == MULTIPLICATION) return left_value * right_value;
    if (operatation == DIVISION)
    {
        if(right_value == T()) throw std::invalid_argument("pamietaj cholero nie dziel przez zero");
        else return left_value / right_value;
    }
    return 0;
}

template<typename T>
std::string NodeOperatorTwoArguments<T>::toString() const
{
    return operatation;
}

template<typename T>
NodeOperatorTwoArguments<T>::~NodeOperatorTwoArguments()
{
    delete left;
    delete right;
}

template<typename T>
NodeOperatorTwoArguments<T>* NodeOperatorTwoArguments<T>::clone() const
{
    return new NodeOperatorTwoArguments(*this);
}

template<typename T>
std::vector<Node<T>*> NodeOperatorTwoArguments<T>::getVariables() const
{
    return std::vector<Node<T>*>() = {left, right};
}