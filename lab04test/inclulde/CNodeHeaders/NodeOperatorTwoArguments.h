#include <iostream>
#include "Node.h"
#pragma once

template<typename T>
class NodeOperatorTwoArguments : public Node<T>
{
private:
    Node<T>* left;
    Node<T>* right;
    std::string operatation;
    [[nodiscard]] T evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    NodeOperatorTwoArguments(std::string op, Node<T>* left, Node<T>* right) : operatation(op), left(left), right(right) {};
    [[nodiscard]] NodeOperatorTwoArguments* clone() const override;
    [[nodiscard]] std::vector<Node<T>*> getVariables() const override;
    ~NodeOperatorTwoArguments() override;
    template<typename> friend class ExpressionTree;
    NodeOperatorTwoArguments(const NodeOperatorTwoArguments& other)
            : operatation(other.operatation), left(other.left->clone()), right(other.right->clone()) {};
};


#include "../CNodeTPP/NodeOperatorTwoArguments.tpp"
