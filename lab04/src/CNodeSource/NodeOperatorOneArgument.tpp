template<typename T>
std::string NodeOperatorOneArgument<T>::toString() const
{
    return operatation;
}

template<typename T>
std::vector<Node<T>*> NodeOperatorOneArgument<T>::getVariables() const
{
    return std::vector<Node<T>*>() = {child};
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