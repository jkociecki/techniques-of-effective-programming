#include "CNode.h"
#pragma once


class CLeaf : public CNode
{
private:
    double value;
    CLeaf(double value) : value(value) {};
    CLeaf(const CLeaf& other) : value(other.value) {};
    double evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] std::vector<CNode*> getVariables() const override;
    ~CLeaf() override = default;
    [[nodiscard]] CLeaf* clone() const override;
    friend class CTree;

};

