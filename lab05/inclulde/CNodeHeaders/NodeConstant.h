#include "Node.h"
#pragma once


template<typename T> class NodeConstant : public Node<T>
{
private:
    T value;

    NodeConstant(T value) : value(value) {};
    NodeConstant(const NodeConstant& other) : value(other.value) {};
    NodeConstant(NodeConstant&& other) : value(other.value) {};
    ~NodeConstant() override = default;

    [[nodiscard]] T evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] std::vector<Node<T>*> getVariables() const override;
    [[nodiscard]] NodeConstant<T>* clone() const override;
    template<typename> friend class ExpressionTree;
};
#include "../../src/CNodeSource/NodeConstant.tpp"