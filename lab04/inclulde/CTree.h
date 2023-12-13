#include "CNodeHeaders/CNode.h"
#include "CNodeHeaders/CNodeOneArguemnt.h"
#include "CNodeHeaders/CNodeTwoArguments.h"
#include "CNodeHeaders/CLeaf.h"
#include "CNodeHeaders/CVariable.h"
#include <string>
#include <vector>
#include <set>
#pragma once


class CTree
{
public:
    CNode* root;

    CTree() : root(nullptr) {};
    CTree(const std::string& expression);
    CTree(const CTree& other);
    ~CTree();
    void initializeVariables(std::vector<double>& expression);


    CTree operator+(const CTree& other) const;
    CTree& operator=(const CTree& other);
    [[nodiscard]] double evaluate() const;
    [[nodiscard]] int getVariablesCount() const;
    [[nodiscard]] std::string toString() const;
    [[nodiscard]] std::string varsToString() const;
    [[nodiscard]] std::string treeStructure() const;

private:
    static bool isOperatorOneArgument(const std::string& token);
    static bool isOperatorTwoArgument(const std::string& token);
    static bool isNumber(const std::string& token);

    void initializeVariablesRecursive(CNode* root_a, std::vector<double>& expression);
    void createPrefix(CNode* root_a, std::string& result) const;
    void createVariables(CNode* root_a, std::vector<std::string>& variables) const;
    void printTreeStructureRecursive(CNode* root_a, int level, std::string& result) const;
    CNode* createTreeRecursive(std::vector<std::string>& expression, bool& ifError);





};



