#include <iostream>
#include "CNode.h"
#pragma once


class CNodeTwoArguments : public CNode
{
public:
    CNode* left;
    CNode* right;
    std::string operatation;
    double evaluate() const override;
    std::string toString() const override;
    CNodeTwoArguments(std::string op, CNode* left, CNode* right) : operatation(op), left(left), right(right) {};

};

