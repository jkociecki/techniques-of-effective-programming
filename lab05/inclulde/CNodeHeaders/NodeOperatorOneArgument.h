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

    NodeOperatorOneArgument(std::string op, Node<T>* child) : operatation(op), child(child) {};
    NodeOperatorOneArgument(const NodeOperatorOneArgument& other)
        : operatation(other.operatation), child(other.child->clone()) {};
    NodeOperatorOneArgument(NodeOperatorOneArgument&& other);
    ~NodeOperatorOneArgument() override;

    [[nodiscard]] T evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] std::vector<Node<T>*> getVariables() const override;
    [[nodiscard]] NodeOperatorOneArgument* clone() const override;
    template<typename> friend class ExpressionTree;
};


#include "../../src/CNodeSource/NodeOperatorOneArgument.tpp"