#include "Node.h"
#pragma once


class NodeConstant : public Node
{
private:
    double value;
    NodeConstant(double value) : value(value) {};
    NodeConstant(const NodeConstant& other) : value(other.value) {};
    double evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] std::vector<Node*> getVariables() const override;
    ~NodeConstant() override = default;
    [[nodiscard]] NodeConstant* clone() const override;
    friend class ExpressionTree;

};

