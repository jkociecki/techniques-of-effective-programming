#pragma once
#include <iostream>
#include <vector>

class CNode
{
public:
    virtual double evaluate() const = 0;
    virtual std::string toString() const = 0;
    virtual std::vector<CNode*> getVariables() const = 0;
    virtual ~CNode() {};
};
