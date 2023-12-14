#include "../inclulde/ExpressionTree.h"
#include <sstream>
#include <unordered_set>


ExpressionTree::ExpressionTree(const std::string& expression)
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

ExpressionTree::ExpressionTree(const ExpressionTree &other)
{
    root = other.root->clone();
}

double ExpressionTree::evaluate() const
{
    return root->evaluate();
}

ExpressionTree::~ExpressionTree()
{
    delete root;
}

void ExpressionTree::initializeVariablesRecursive(Node* root_a, std::vector<double>& expression)
{
    if(root_a == nullptr) return;
    auto* var = dynamic_cast<NodeVariable*>(root_a);
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
    std::vector<Node*> children = root_a->getVariables();
    for(Node* child : children)
    {
        initializeVariablesRecursive(child, expression);
    }
}

void ExpressionTree::createPrefix(Node *root_a, std::string &result) const
{
    result += " " + root_a->toString();
    if(!root_a->getVariables().empty())
    {
        for(Node* child : root_a->getVariables())
        {
            createPrefix(child, result);
        }
    }
}

std::string ExpressionTree::toString() const
{
    std::string result;
    createPrefix(root, result);
    return result;
}

Node* ExpressionTree::createTreeRecursive(std::vector<std::string>& expression, bool& ifError)
{
    if (expression.empty())
    {
        ifError = false;
        return new NodeConstant(1);
    }

    std::string token = expression.front();
    expression.erase(expression.begin());

    if (isOperatorTwoArgument(token))
    {
        Node* left = createTreeRecursive(expression, ifError);
        Node* right = createTreeRecursive(expression, ifError);
        return new NodeOperatorTwoArguments(token, left, right);
    }
    else if (isOperatorOneArgument(token))
    {
        Node* child = createTreeRecursive(expression, ifError);
        return new NodeOperatorOneArgument(token, child);
    }
    else if (isNumber(token))
    {
        return new NodeConstant(std::stod(token));
    }
    else
    {
        return new NodeVariable(token, 0);
    }
}

//TODO: moze dodac virtualna metode set child
ExpressionTree ExpressionTree::operator+(const ExpressionTree &other) const
{
    ExpressionTree result(*this);
    Node* leaf = result.root;
    Node* parent_of_leaf = nullptr;
    while(!leaf->getVariables().empty())
    {
        parent_of_leaf = leaf;
        leaf = leaf->getVariables()[0];
    }

    if(dynamic_cast<NodeOperatorOneArgument*>(parent_of_leaf) != nullptr)
    {
       auto* res = dynamic_cast<NodeOperatorOneArgument*>(parent_of_leaf);
       res->child = other.root->clone();
    }
    else if(dynamic_cast<NodeOperatorTwoArguments*>(parent_of_leaf) != nullptr)
    {
        auto* res = dynamic_cast<NodeOperatorTwoArguments*>(parent_of_leaf);
        res->left = other.root->clone();
    }
    return result;
}


ExpressionTree& ExpressionTree::operator=(const ExpressionTree &other)
{
    if(this != &other)
    {
        delete root;
        root = other.root->clone();
    }
    return *this;
}


bool ExpressionTree::isOperatorTwoArgument(const std::string &token)
{
    return token == ADDITION || token == SUBTRACTION || token == MULTIPLICATION || token == DIVISION;
}

bool ExpressionTree::isNumber(const std::string &token)
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


bool ExpressionTree::isOperatorOneArgument(const std::string &token)
{
    return token == SIN || token == COS;
}

void ExpressionTree::initializeVariables(std::vector<double> &expression)
{
    initializeVariablesRecursive(root, expression);
}

void ExpressionTree::createVariables(Node *root_a, std::vector<std::string>& variables) const
{
    if(root_a == nullptr) return;
    auto* var = dynamic_cast<NodeVariable*>(root_a);
    if(var != nullptr)
    {
        variables.push_back(var->toString());
        return;
    }
    for(Node* child : root_a->getVariables())
    {
        createVariables(child, variables);
    }
}

std::string ExpressionTree::varsToString() const
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

int ExpressionTree::getVariablesCount() const
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

void ExpressionTree::printTreeStructureRecursive(Node *root_a, int level, std::string &result) const
{
    if(root_a != nullptr)
    {
        for(int i = 0; i < level; ++i)
        {
            result += "  ";
        }
        result += "|--" + root_a->toString() + "\n";
        for(Node* child : root_a->getVariables())
        {
            printTreeStructureRecursive(child, level + 1, result);
        }
    }
}

std::string ExpressionTree::treeStructure() const
{
    std::string result;
    printTreeStructureRecursive(root, 0, result);
    return result;
}







