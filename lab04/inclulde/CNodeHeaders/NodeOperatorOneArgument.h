#include "Node.h"
#include <iostream>
#include <string>
#pragma once


class NodeOperatorOneArgument : public Node
{
private:
    Node* child;
    std::string operatation;
    [[nodiscard]] double evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    NodeOperatorOneArgument(std::string op, Node* child) : operatation(op), child(child) {};
    NodeOperatorOneArgument(const NodeOperatorOneArgument& other): operatation(other.operatation), child(other.child->clone()) {};
    [[nodiscard]] NodeOperatorOneArgument* clone() const override;
    [[nodiscard]] std::vector<Node*> getVariables() const override;
    ~NodeOperatorOneArgument() override;
    friend class ExpressionTree;

};