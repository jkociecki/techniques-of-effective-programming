#include "../../inclulde/CNodeHeaders/CVariable.h"

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

CVariable* CVariable::clone() const
{
    return new CVariable(*this);
}