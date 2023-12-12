#include "../inclulde/CNodeTwoArguments.h"

double CNodeTwoArguments::evaluate() const {
    double left_value = left->evaluate();
    double right_value = right->evaluate();

    if (operatation == "+") return left_value + right_value;
    if (operatation == "-") return left_value - right_value;
    if (operatation == "*") return left_value * right_value;
    if (operatation == "/") return left_value / right_value;

    return 0;
}


std::string CNodeTwoArguments::toString() const
{
    return operatation;
}