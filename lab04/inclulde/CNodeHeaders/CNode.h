#pragma once
#include <iostream>
#include <vector>

class CNode
{
public:
    [[nodiscard]] virtual double evaluate() const = 0;
    [[nodiscard]] virtual std::string toString() const = 0;
    [[nodiscard]] virtual std::vector<CNode*> getVariables() const = 0;
    [[nodiscard]] virtual CNode* clone() const = 0;
    virtual ~CNode() = default;
};

