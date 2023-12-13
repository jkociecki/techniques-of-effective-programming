#include "../../inclulde/CNodeHeaders/NodeVariable.h"

double NodeVariable::evaluate() const
{
    return value;
}

std::string NodeVariable::toString() const
{
    return name;
}

std::vector<Node*> NodeVariable::getVariables() const
{
    return {};

}

NodeVariable* NodeVariable::clone() const
{
    return new NodeVariable(*this);
}