#include "CNode.h"
#include <iostream>
#include <string>
#pragma once


class CNodeOneArgument : public CNode
{
public:
    CNode* child;
    std::string operatation;
    double evaluate() const override;
    std::string toString() const override;
    CNodeOneArgument(std::string op, CNode* child) : operatation(op), child(child) {};
    std::vector<CNode*> getVariables() const override;
    ~CNodeOneArgument() override;


};