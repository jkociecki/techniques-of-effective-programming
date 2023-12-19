#include "Node.h"
#include <iostream>
#include <string>
#include <cmath>
#pragma once



template<typename T>
class NodeOperatorOneArgument : public Node<T>
{
private:
    Node<T>* child;
    std::string operatation;
    [[nodiscard]] T evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    NodeOperatorOneArgument(std::string op, Node<T>* child) : operatation(op), child(child) {};
    [[nodiscard]] std::vector<Node<T>*> getVariables() const override;
    ~NodeOperatorOneArgument() override;
    [[nodiscard]] NodeOperatorOneArgument* clone() const override;
    NodeOperatorOneArgument(const NodeOperatorOneArgument& other): operatation(other.operatation), child(other.child->clone()) {};
    template<typename> friend class ExpressionTree;
};


#include "../../src/CNodeSource/NodeOperatorOneArgument.tpp"