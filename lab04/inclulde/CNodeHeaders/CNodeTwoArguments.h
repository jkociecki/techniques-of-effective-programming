#include <iostream>
#include "CNode.h"
#pragma once


class CNodeTwoArguments : public CNode
{
private:
    CNode* left;
    CNode* right;
    std::string operatation;
    [[nodiscard]] double evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    CNodeTwoArguments(std::string op, CNode* left, CNode* right) : operatation(op), left(left), right(right) {};
    CNodeTwoArguments(const CNodeTwoArguments& other)
    : operatation(other.operatation), left(other.left->clone()), right(other.right->clone()) {};
    [[nodiscard]] CNodeTwoArguments* clone() const override;
    [[nodiscard]] std::vector<CNode*> getVariables() const override;
    ~CNodeTwoArguments() override;
    friend class CTree;


};

