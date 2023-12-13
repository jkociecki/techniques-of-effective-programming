#include "../../inclulde/CNodeHeaders/NodeConstant.h"

double NodeConstant::evaluate() const
{
    return value;
}

std::string NodeConstant::toString() const
{
    return std::to_string(value);
}

std::vector<Node*> NodeConstant::getVariables() const
{
    return {};
}

NodeConstant* NodeConstant::clone() const
{
    return new NodeConstant(*this);
}