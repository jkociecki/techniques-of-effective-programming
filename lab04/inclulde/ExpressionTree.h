#include "CNodeHeaders/Node.h"
#include "CNodeHeaders/NodeOperatorOneArgument.h"
#include "CNodeHeaders/NodeOperatorTwoArguments.h"
#include "CNodeHeaders/NodeConstant.h"
#include "CNodeHeaders/NodeVariable.h"
#include <string>
#include <vector>
#include <set>
#pragma once


class ExpressionTree
{
public:
    Node* root;

    ExpressionTree() : root(nullptr) {};
    ExpressionTree(const std::string& expression);
    ExpressionTree(const ExpressionTree& other);
    ~ExpressionTree();
    void initializeVariables(std::vector<double>& expression);

    ExpressionTree operator+(const ExpressionTree& other) const;
    ExpressionTree& operator=(const ExpressionTree& other);

    [[nodiscard]] double evaluate() const;
    [[nodiscard]] int getVariablesCount() const;
    [[nodiscard]] std::string toString() const;
    [[nodiscard]] std::string varsToString() const;
    [[nodiscard]] std::string treeStructure() const;

private:
    static bool isOperatorOneArgument(const std::string& token);
    static bool isOperatorTwoArgument(const std::string& token);
    static bool isNumber(const std::string& token);

    void initializeVariablesRecursive(Node* root_a, std::vector<double>& expression);
    void createPrefix(Node* root_a, std::string& result) const;
    void createVariables(Node* root_a, std::vector<std::string>& variables) const;
    void printTreeStructureRecursive(Node* root_a, int level, std::string& result) const;
    Node* createTreeRecursive(std::vector<std::string>& expression, bool& ifError);
};



