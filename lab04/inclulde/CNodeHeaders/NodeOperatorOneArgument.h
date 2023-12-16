#include "Node.h"
#include <iostream>
#include <string>
#include <cmath>
#pragma once



template<typename T>
class NodeOperatorOneArgument : public Node<T>
{
protected:
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

template<typename T>
T NodeOperatorOneArgument<T>::evaluate() const
{
    double child_value = child->evaluate();
    if(operatation == SIN) return sin(child_value);
    if(operatation == COS) return cos(child_value);
    return 0;
}

#include "../../src/CNodeSource/NodeOperatorOneArgument.tpp"