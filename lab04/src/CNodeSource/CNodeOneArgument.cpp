#include "../../inclulde/CNodeHeaders/NodeOperatorOneArgument.h"
#include <cmath>

double NodeOperatorOneArgument::evaluate() const
{
    double child_value = child->evaluate();
    if(operatation == SIN) return sin(child_value);
    if(operatation == COS) return cos(child_value);
    return 0;
}

std::string NodeOperatorOneArgument::toString() const
{
    return operatation;
}

std::vector<Node*> NodeOperatorOneArgument::getVariables() const
{
    return std::vector<Node*>() = {child};
}

NodeOperatorOneArgument::~NodeOperatorOneArgument()
{
    delete child;
}

NodeOperatorOneArgument* NodeOperatorOneArgument::clone() const
{
    return new NodeOperatorOneArgument(*this);
}