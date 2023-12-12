#include "../inclulde/CVariable.h"

double CVariable::evaluate() const
{
    return value;
}

std::string CVariable::toString() const
{
    return name;
}

std::vector<CNode*> CVariable::getVariables() const
{
    return {};
}