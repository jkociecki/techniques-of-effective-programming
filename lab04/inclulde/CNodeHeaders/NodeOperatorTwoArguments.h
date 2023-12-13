#include <iostream>
#include "Node.h"
#pragma once


class NodeOperatorTwoArguments : public Node
{
private:
    Node* left;
    Node* right;
    std::string operatation;
    [[nodiscard]] double evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    NodeOperatorTwoArguments(std::string op, Node* left, Node* right) : operatation(op), left(left), right(right) {};
    NodeOperatorTwoArguments(const NodeOperatorTwoArguments& other)
    : operatation(other.operatation), left(other.left->clone()), right(other.right->clone()) {};
    [[nodiscard]] NodeOperatorTwoArguments* clone() const override;
    [[nodiscard]] std::vector<Node*> getVariables() const override;
    ~NodeOperatorTwoArguments() override;
    friend class ExpressionTree;


};

