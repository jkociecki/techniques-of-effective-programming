#include "Node.h"
#pragma once


template<typename T> class NodeConstant : public Node<T>
{
protected:
    T value;
    NodeConstant(T value) : value(value) {};
    NodeConstant(const NodeConstant& other) : value(other.value) {};
    T evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] std::vector<Node<T>*> getVariables() const override;
    ~NodeConstant() override = default;
    [[nodiscard]] NodeConstant* clone() const override;
    template<typename> friend class ExpressionTree;
};

#include "../../src/CNodeSource/NodeConstant.tpp"
