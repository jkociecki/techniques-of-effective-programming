#include "CNodeHeaders/CNode.h"
#include "CNodeHeaders/CNodeOneArguemnt.h"
#include "CNodeHeaders/CNodeTwoArguments.h"
#include "CNodeHeaders/CLeaf.h"
#include "CNodeHeaders/CVariable.h"
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
    void initializeVariables(std::vector<std::string>& expression);

    CTree operator+(const CTree& other) const;
    CTree& operator=(const CTree& other);
    [[nodiscard]] double evaluate() const;
    [[nodiscard]] std::string toString() const;

private:
    static bool isOperatorOneArgument(const std::string& token);
    static bool isOperatorTwoArgument(const std::string& token);
    static bool isNumber(const std::string& token);

    void initializeVariablesRecursive(CNode* root_a, std::vector<std::string>& expression);
    void createPrefix(CNode* root_a, std::string& result) const;
    CNode* createTreeRecursive(std::vector<std::string>& expression, bool& ifError);





};



