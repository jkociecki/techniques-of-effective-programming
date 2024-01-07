template<typename T>
T NodeVariable<T>::evaluate() const
{
    return value;
}

template<typename T>
std::string NodeVariable<T>::toString() const
{
    return name;
}

template<typename T>
std::vector<Node<T>*> NodeVariable<T>::getVariables() const
{
    return std::vector<Node<T>*>();
}


template<typename T>
NodeVariable<T>* NodeVariable<T>::clone() const
{
    return new NodeVariable(*this);
}