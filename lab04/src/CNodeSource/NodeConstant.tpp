#pragma once

template<typename T>
T NodeConstant<T>::evaluate() const
{
    return value;
}

template<typename T>
std::string NodeConstant<T>::toString() const
{
    return std::to_string(value);
}

template<typename T>
std::vector<Node<T>*> NodeConstant<T>::getVariables() const
{
    return {};
}

template<typename T>
NodeConstant<T>* NodeConstant<T>::clone() const
{
    return new NodeConstant(*this);
}

template<>
std::string NodeConstant<std::string>::toString() const
{
    return value;
}
