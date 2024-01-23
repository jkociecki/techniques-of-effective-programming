#include "Node.h"
#include "NodeOperatorOneArgument.h"
#include "NodeOperatorTwoArguments.h"
#include "NodeConstant.h"
#include "NodeVariable.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <sstream>
#include <unordered_set>

#pragma once




template<typename T>
class ExpressionTree
{
public:

    ExpressionTree() : root(nullptr) {};
    explicit ExpressionTree(const std::string& expression);
    ExpressionTree(const ExpressionTree& other);
    ExpressionTree(ExpressionTree&& other) noexcept;
    ~ExpressionTree();

    void initializeVariables(std::unordered_map<std::string,T>& expression);

    ExpressionTree operator+(const ExpressionTree& other) const;
    ExpressionTree operator+(ExpressionTree&& other) const;

    ExpressionTree& operator=(const ExpressionTree<T>& other);
    ExpressionTree& operator=(ExpressionTree<T>&& other) noexcept;

    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] T evaluate() const;
    [[nodiscard]] int getVariablesCount() const;
    [[nodiscard]] std::string toString() const;
    [[nodiscard]] std::string varsToString() const;
    [[nodiscard]] std::string treeStructure() const;

private:
    Node<T>* root;
    static bool isOperatorOneArgument(const std::string& token);
    static bool isOperatorTwoArgument(const std::string& token);
    static bool isNumber(const std::string& token);
    void initializeVariablesRecursive(Node<T>* root_a, std::unordered_map<std::string,T>& expression);
    void createPrefix(Node<T>* root_a, std::string& result) const;
    void createVariables(Node<T>* root_a, std::vector<std::string>& variables) const;
    void printTreeStructureRecursive(Node<T>* root_a, int level, std::string& result) const;
    Node<T>* createTreeRecursive(std::vector<std::string>& expression, bool& ifError);

};


#include "ExpressionTree.tpp"