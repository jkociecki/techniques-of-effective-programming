#include "../../inclulde/CNodeHeaders/NodeOperatorTwoArguments.h"

double NodeOperatorTwoArguments::evaluate() const {
    double left_value = left->evaluate();
    double right_value = right->evaluate();

    if (operatation == ADDITION) return left_value + right_value;
    if (operatation == SUBTRACTION) return left_value - right_value;
    if (operatation == MULTIPLICATION) return left_value * right_value;
    if (operatation == DIVISION) return left_value / right_value;

    return 0;
}


std::string NodeOperatorTwoArguments::toString() const
{
    return operatation;
}

std::vector<Node*> NodeOperatorTwoArguments::getVariables() const
{
    return std::vector<Node*>() = {left, right};
}

NodeOperatorTwoArguments::~NodeOperatorTwoArguments()
{
    delete left;
    delete right;
}

NodeOperatorTwoArguments* NodeOperatorTwoArguments::clone() const
{
    return new NodeOperatorTwoArguments(*this);
}