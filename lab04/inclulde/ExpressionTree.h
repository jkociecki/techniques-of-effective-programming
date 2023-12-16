#include "CNodeHeaders/Node.h"
#include "CNodeHeaders/NodeOperatorOneArgument.h"
#include "CNodeHeaders/NodeOperatorTwoArguments.h"
#include "CNodeHeaders/NodeConstant.h"
#include "CNodeHeaders/NodeVariable.h"
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <unordered_set>

#pragma once

template<typename T>
class ExpressionTree
{
public:
    Node<T>* root;

    ExpressionTree() : root(nullptr) {};
    ExpressionTree(const std::string& expression);
    ExpressionTree(const ExpressionTree& other);
    ~ExpressionTree();
    void initializeVariables(std::vector<double>& expression);

    ExpressionTree operator+(const ExpressionTree& other) const;
    ExpressionTree& operator=(const ExpressionTree& other);

    [[nodiscard]] T evaluate() const;
    [[nodiscard]] int getVariablesCount() const;
    [[nodiscard]] std::string toString() const;
    [[nodiscard]] std::string varsToString() const;
    [[nodiscard]] std::string treeStructure() const;

private:
    static bool isOperatorOneArgument(const std::string& token);
    static bool isOperatorTwoArgument(const std::string& token);
    static bool isNumber(const std::string& token);

    void initializeVariablesRecursive(Node<T>* root_a, std::vector<double>& expression);
    void createPrefix(Node<T>* root_a, std::string& result) const;
    void createVariables(Node<T>* root_a, std::vector<std::string>& variables) const;
    void printTreeStructureRecursive(Node<T>* root_a, int level, std::string& result) const;
    Node<T>* createTreeRecursive(std::vector<std::string>& expression, bool& ifError);
};

#include "../src/ExpressionTree.tpp"