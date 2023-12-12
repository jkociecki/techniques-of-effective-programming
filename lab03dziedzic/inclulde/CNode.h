#pragma once
#include <iostream>

class CNode
{
public:
    virtual double evaluate() const = 0;
    virtual std::string toString() const = 0;
};
