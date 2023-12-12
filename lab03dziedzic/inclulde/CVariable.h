#include "CNode.h"
#include <iostream>
#pragma once

class CVariable : public CNode
{
public:
    std::string name;
    double value;
    double evaluate() const override;
    std::string toString() const override;
    CVariable(std::string name, double value) : name(name), value(value) {};


};


