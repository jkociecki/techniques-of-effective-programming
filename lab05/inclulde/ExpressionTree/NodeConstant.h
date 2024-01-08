#include "Node.h"
#pragma once


template<typename T> class NodeConstant : public Node<T>
{
private:
    T value;

    NodeConstant(T value) : value(value) {};
    NodeConstant(const NodeConstant& other) : value(other.value) {};
    ~NodeConstant() override = default;

    [[nodiscard]] T evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] std::vector<Node<T>*> getVariables() const override;
    [[nodiscard]] NodeConstant<T>* clone() const override;
    template<typename> friend class ExpressionTree;
};

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