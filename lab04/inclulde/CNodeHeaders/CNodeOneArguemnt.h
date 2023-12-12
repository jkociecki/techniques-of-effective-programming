#include "CNode.h"
#include <iostream>
#include <string>
#pragma once


class CNodeOneArgument : public CNode
{
private:
    CNode* child;
    std::string operatation;
    [[nodiscard]] double evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    CNodeOneArgument(std::string op, CNode* child) : operatation(op), child(child) {};
    CNodeOneArgument(const CNodeOneArgument& other): operatation(other.operatation), child(other.child->clone()) {};
    [[nodiscard]] CNodeOneArgument* clone() const override;
    [[nodiscard]] std::vector<CNode*> getVariables() const override;
    ~CNodeOneArgument() override;
    friend class CTree;

};