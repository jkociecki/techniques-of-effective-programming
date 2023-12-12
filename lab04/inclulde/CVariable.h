#include "CNode.h"
#include <iostream>
#pragma once

class CVariable : public CNode
{
private:
    std::string name;
    double value;
    double evaluate() const override;
    std::string toString() const override;
    CVariable(std::string name, double value) : name(name), value(value) {};
    CVariable(const CVariable& other) : name(other.name), value(other.value) {};
    CVariable* clone() const override;
    std::vector<CNode*> getVariables() const override;
    ~CVariable() override = default;


    friend class CTree;
};


