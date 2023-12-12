#include "CNode.h"
#include <iostream>
#pragma once

class CVariable : public CNode
{
private:
    std::string name;
    double value;
    [[nodiscard]] double evaluate() const override;
    [[nodiscard]] std::string toString() const override;
    CVariable(std::string name, double value) : name(name), value(value) {};
    CVariable(const CVariable& other) : name(other.name), value(other.value) {};
    [[nodiscard]] CVariable* clone() const override;
    [[nodiscard]] std::vector<CNode*> getVariables() const override;
    ~CVariable() override = default;


    friend class CTree;
};


