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

template<typename T>
ExpressionTree<T>::ExpressionTree(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string token;
    std::vector<std::string> tokens;
    while (iss >> token)
    {
        tokens.push_back(token);
    }
    bool isExpressionCorrect = true;
    root = createTreeRecursive(tokens, isExpressionCorrect);

    if(!isExpressionCorrect || !tokens.empty())
    {
        std::cout << "CORRECTED EXPRESSION: " << toString() << std::endl;
    }
}

template<typename T>
ExpressionTree<T>::ExpressionTree(const ExpressionTree<T> &other)
{
    root = other.root->clone();
}

template<typename T>
T ExpressionTree<T>::evaluate() const
{
    return root->evaluate();
}

template<typename T>
ExpressionTree<T>::~ExpressionTree()
{
    delete root;
}

template<typename T>
void ExpressionTree<T>::initializeVariablesRecursive(Node<T>* root_a, std::vector<double>& expression)
{
    if(root_a == nullptr) return;
    auto* var = dynamic_cast<NodeVariable<T>*>(root_a);
    if(var != nullptr)
    {
        if(!expression.empty())
        {
            double token = expression.front();
            expression.erase(expression.begin());
            var->value = token;
        }
        return;
    }
    std::vector<Node<T>*> children = root_a->getVariables();
    for(Node<T>* child : children)
    {
        initializeVariablesRecursive(child, expression);
    }
}

template<typename T>
void ExpressionTree<T>::createPrefix(Node<T> *root_a, std::string &result) const
{
    result += " " + root_a->toString();
    if(!root_a->getVariables().empty())
    {
        for(Node<T>* child : root_a->getVariables())
        {
            createPrefix(child, result);
        }
    }
}

template<typename T>
std::string ExpressionTree<T>::toString() const
{
    std::string result;
    createPrefix(root, result);
    return result;
}

template<typename T>
Node<T>* ExpressionTree<T>::createTreeRecursive(std::vector<std::string>& expression, bool& ifError)
{
    if (expression.empty())
    {
        ifError = false;
        return new NodeConstant<T>(1);
    }

    std::string token = expression.front();
    expression.erase(expression.begin());

    if (isOperatorTwoArgument(token))
    {
        Node<T>* left = createTreeRecursive(expression, ifError);
        Node<T>* right = createTreeRecursive(expression, ifError);
        return new NodeOperatorTwoArguments(token, left, right);
    }
    else if (isOperatorOneArgument(token))
    {
        Node<T>* child = createTreeRecursive(expression, ifError);
        return new NodeOperatorOneArgument(token, child);
    }
    else if (isNumber(token))
    {
        return new NodeConstant<T>(std::stod(token));
    }
    else
    {
        return new NodeVariable<T>(token, 0);
    }
}

template<typename T>
ExpressionTree<T> ExpressionTree<T>::operator+(const ExpressionTree<T> &other) const
{
    ExpressionTree result(*this);
    Node<T>* leaf = result.root;
    Node<T>* parent_of_leaf = nullptr;
    while(!leaf->getVariables().empty())
    {
        parent_of_leaf = leaf;
        leaf = leaf->getVariables()[0];
    }

    if(dynamic_cast<NodeOperatorOneArgument<T>*>(parent_of_leaf) != nullptr)
    {
        auto* res = dynamic_cast<NodeOperatorOneArgument<T>*>(parent_of_leaf);
        res->child = other.root->clone();
    }
    else if(dynamic_cast<NodeOperatorTwoArguments<T>*>(parent_of_leaf) != nullptr)
    {
        auto* res = dynamic_cast<NodeOperatorTwoArguments<T>*>(parent_of_leaf);
        res->left = other.root->clone();
    }
    return result;
}

template<typename T>
ExpressionTree<T>& ExpressionTree<T>::operator=(const ExpressionTree<T> &other)
{
    if(this != &other)
    {
        delete root;
        root = other.root->clone();
    }
    return *this;
}

template<typename T>
bool ExpressionTree<T>::isOperatorTwoArgument(const std::string &token)
{
    return token == ADDITION || token == SUBTRACTION || token == MULTIPLICATION || token == DIVISION;
}

template<typename T>
bool ExpressionTree<T>::isNumber(const std::string &token)
{
    for (char c : token)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

template<typename T>
bool ExpressionTree<T>::isOperatorOneArgument(const std::string &token)
{
    return token == SIN || token == COS;
}

template<typename T>
void ExpressionTree<T>::initializeVariables(std::vector<double> &expression)
{
    initializeVariablesRecursive(root, expression);
}

template<typename T>
void ExpressionTree<T>::createVariables(Node<T>* root_a, std::vector<std::string>& variables) const
{
    if(root_a == nullptr) return;
    auto* var = dynamic_cast<NodeVariable<T>*>(root_a);
    if(var != nullptr)
    {
        variables.push_back(var->toString());
        return;
    }
    for(Node<T>* child : root_a->getVariables())
    {
        createVariables(child, variables);
    }
}

template<typename T>
std::string ExpressionTree<T>::varsToString() const
{
    std::vector<std::string> vars;
    std::unordered_set<std::string> vars_set;
    createVariables(root, vars);
    for(const auto & var : vars)
    {
        vars_set.insert(var);
    }
    std::string result;
    for(const std::string& var : vars)
    {
        result += var + " ";
    }
    return result;
}

template<typename T>
int ExpressionTree<T>::getVariablesCount() const
{
    std::vector<std::string> vars;
    std::unordered_set<std::string> vars_set;
    createVariables(root, vars);
    for(const auto & var : vars)
    {
        vars_set.insert(var);
    }
    return vars_set.size();
}

template<typename T>
void ExpressionTree<T>::printTreeStructureRecursive(Node<T>* root_a, int level, std::string &result) const
{
    if(root_a != nullptr)
    {
        for(int i = 0; i < level; ++i)
        {
            result += "  ";
        }
        result += "|--" + root_a->toString() + "\n";
        for(Node<T>* child : root_a->getVariables())
        {
            printTreeStructureRecursive(child, level + 1, result);
        }
    }
}

template<typename T>
std::string ExpressionTree<T>::treeStructure() const
{
    std::string result;
    printTreeStructureRecursive(root, 0, result);
    return result;
}








