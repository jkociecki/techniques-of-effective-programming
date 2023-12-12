#include "../inclulde/CLeaf.h"

double CLeaf::evaluate() const
{
    return value;
}

std::string CLeaf::toString() const
{
    return std::to_string(value);
}

std::vector<CNode*> CLeaf::getVariables() const
{
    return {};
}

CLeaf* CLeaf::clone() const
{
    return new CLeaf(*this);
}