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

    NodeOperatorTwoArguments(std::string op, Node<T>* left, Node<T>* right)
        : operatation(op), left(left), right(right) {};
    NodeOperatorTwoArguments(const NodeOperatorTwoArguments& other)
            : operatation(other.operatation), left(other.left->clone()), right(other.right->clone()) {};
    NodeOperatorTwoArguments(NodeOperatorTwoArguments&& other);
    ~NodeOperatorTwoArguments() override;


    [[nodiscard]] T evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] NodeOperatorTwoArguments* clone() const override;
    [[nodiscard]] std::vector<Node<T>*> getVariables() const override;
    template<typename> friend class ExpressionTree;
};


#include "../../src/CNodeSource/NodeOperatorTwoArguments.tpp"