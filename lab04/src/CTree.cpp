#include "../inclulde/CTree.h"
#include <sstream>
#include <unordered_set>


CTree::CTree(const std::string& expression)
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

CTree::CTree(const CTree &other)
{
    root = other.root->clone();
}

double CTree::evaluate() const
{
    return root->evaluate();
}

CTree::~CTree()
{
    delete root;
}

void CTree::initializeVariablesRecursive(CNode* root_a, std::vector<double>& expression)
{
    if(root_a == nullptr) return;
    CVariable* var = dynamic_cast<CVariable*>(root_a);
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
    std::vector<CNode*> children = root_a->getVariables();
    for(CNode* child : children)
    {
        initializeVariablesRecursive(child, expression);
    }
}

void CTree::createPrefix(CNode *root_a, std::string &result) const
{
    result += " " + root_a->toString();
    if(!root_a->getVariables().empty())
    {
        for(CNode* child : root_a->getVariables())
        {
            createPrefix(child, result);
        }
    }
}

std::string CTree::toString() const
{
    std::string result;
    createPrefix(root, result);
    return result;
}

CNode* CTree::createTreeRecursive(std::vector<std::string>& expression, bool& ifError)
{
    if (expression.empty())
    {
        ifError = false;
        return new CLeaf(1);
    }


    std::string token = expression.front();
    expression.erase(expression.begin());

    if (isOperatorTwoArgument(token))
    {
        CNode* left = createTreeRecursive(expression, ifError);
        CNode* right = createTreeRecursive(expression, ifError);
        return new CNodeTwoArguments(token, left, right);
    }
    else if (isOperatorOneArgument(token))
    {
        CNode* child = createTreeRecursive(expression, ifError);
        return new CNodeOneArgument(token, child);
    }
    else if (isNumber(token))
    {
        return new CLeaf(std::stod(token));
    }
    else
    {
        return new CVariable(token, 0);
    }
}

CTree CTree::operator+(const CTree &other) const
{
    CTree result(*this);
    CNode* parent = result.root;
    CNode* test = nullptr;
    while(!parent->getVariables().empty())
    {
        test = parent;
        parent = parent->getVariables()[0];
    }

    if(dynamic_cast<CNodeOneArgument*>(test) != nullptr)
    {
       auto* res = dynamic_cast<CNodeOneArgument*>(test);
       res->child = other.root->clone();
    }
    else if(dynamic_cast<CNodeTwoArguments*>(test) != nullptr)
    {
        auto* res = dynamic_cast<CNodeTwoArguments*>(test);
        res->left = other.root->clone();
    }
    return result;
}


CTree& CTree::operator=(const CTree &other)
{
    if(this != &other)
    {
        delete root;
        root = other.root->clone();
    }
    return *this;
}


bool CTree::isOperatorTwoArgument(const std::string &token)
{
    return token == ADDITION || token == SUBTRACTION || token == MULTIPLICATION || token == DIVISION;
}

bool CTree::isNumber(const std::string &token)
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


bool CTree::isOperatorOneArgument(const std::string &token)
{
    return token == SIN || token == COS;
}

void CTree::initializeVariables(std::vector<double> &expression)
{
    initializeVariablesRecursive(root, expression);
}

void CTree::createVariables(CNode *root_a, std::vector<std::string>& variables) const
{
    if(root_a == nullptr) return;
    auto* var = dynamic_cast<CVariable*>(root_a);
    if(var != nullptr)
    {
        variables.push_back(var->toString());
        return;
    }
    for(CNode* child : root_a->getVariables())
    {
        createVariables(child, variables);
    }
}

std::string CTree::varsToString() const
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

int CTree::getVariablesCount() const
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

void CTree::printTreeStructureRecursive(CNode *root_a, int level, std::string &result) const
{
    if(root_a != nullptr)
    {
        for(int i = 0; i < level; ++i)
        {
            result += "  ";
        }
        result += "|--" + root_a->toString() + "\n";
        for(CNode* child : root_a->getVariables())
        {
            printTreeStructureRecursive(child, level + 1, result);
        }
    }
}

std::string CTree::treeStructure() const
{
    std::string result;
    printTreeStructureRecursive(root, 0, result);
    return result;
}







