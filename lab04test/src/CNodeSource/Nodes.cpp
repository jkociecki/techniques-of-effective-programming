#include "../../inclulde/CNodeHeaders/NodeConstant.h"
#include "../../inclulde/CNodeHeaders/NodeOperatorOneArgument.h"


template<>
std::string NodeConstant<std::string>::toString() const
{
    return "\"" + value + "\"";
}

///////////////////////////////////////////////////////////////////////////////
template<>
std::string NodeOperatorOneArgument<std::string>::evaluate() const
{
    std::string child_value = child->evaluate();
    if(operatation == SIN) return toUpper(child_value);
    if(operatation == COS) return toLower(child_value);
    return "";
}