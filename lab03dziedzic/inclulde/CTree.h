#include "CNode.h"
#include "CNodeOneArguemnt.h"
#include "CNodeTwoArguments.h"
#include "CLeaf.h"
#include "CVariable.h"
#include <string>
#include <vector>
#pragma once


class CTree
{
public:
    CNode* root;

    CTree(const std::string& expression);
    CNode* createTreeRecursive(std::vector<std::string>& expression);

    static bool isOperatorOneArgument(const std::string& token);
    static bool isOperatorTwoArgument(const std::string& token);
    static bool isNumber(const std::string& token);
    void initializeVariables(CNode* root_a, std::vector<std::string>& expression);
    double evaluate() const;
    static bool isVariable(CNode* cnode, const std::string& token);


};



