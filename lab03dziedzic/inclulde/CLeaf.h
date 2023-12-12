#include "CNode.h"
#pragma once


class CLeaf : public CNode
{
public:
    double value;
    CLeaf(int value) : value(value) {};
    double evaluate() const override;
    std::string toString() const override;
    std::vector<CNode*> getVariables() const override;
    ~CLeaf() override = default;


};

