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
    CTree(const CTree& other);
    ~CTree();
    CNode* createTreeRecursive(std::vector<std::string>& expression, bool& ifError);

    static bool isOperatorOneArgument(const std::string& token);
    static bool isOperatorTwoArgument(const std::string& token);
    static bool isNumber(const std::string& token);
    void initializeVariables(CNode* root_a, std::vector<std::string>& expression);
    CTree operator+(const CTree& other) const;
    CTree& operator=(const CTree& other);
    void createPrefix(CNode* root_a, std::string& result) const;
    double evaluate() const;
    static bool isVariable(CNode* cnode, const std::string& token);


    std::string toString() const;


};



