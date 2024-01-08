#include "../StringUtils.h"


template<typename T>
std::vector<Node<T>*> NodeOperatorOneArgument<T>::getVariables() const
{
    return std::vector<Node<T> *>() = {child};
}

template<typename T>
T NodeOperatorOneArgument<T>::evaluate() const
{
    T child_value = child->evaluate();
    if(operatation == SIN) return sin(child_value);
    if(operatation == COS) return cos(child_value);
    return 0;
}

template<typename T>
std::string NodeOperatorOneArgument<T>::toString() const
{
    return operatation;
}

template<typename T>
NodeOperatorOneArgument<T>::~NodeOperatorOneArgument()
{
    delete child;
}

template<typename T>
NodeOperatorOneArgument<T>* NodeOperatorOneArgument<T>::clone() const
{
    return new NodeOperatorOneArgument(*this);
}
