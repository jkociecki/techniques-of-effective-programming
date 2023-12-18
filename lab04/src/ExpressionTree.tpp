#include <set>
#include <algorithm>


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
    if(root != nullptr) return root->evaluate();
    else return 0;
}

template<typename T>
ExpressionTree<T>::~ExpressionTree()
{
    delete root;
}

template<typename T>
void ExpressionTree<T>::initializeVariablesRecursive(Node<T>* root_a, std::unordered_map<std::string, T>& expression)
{
    if(root_a == nullptr) return;
    auto* var = dynamic_cast<NodeVariable<T>*>(root_a);
    if(var != nullptr)
    {
        if(!expression.empty())
        {
            auto it = expression.find(var->toString());
            if(it != expression.end()) var->value = it->second;
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
    if(root == nullptr) return "";
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
    if(root == nullptr) return other;
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
        delete res->child;
        res->child = other.root->clone();
    }
    else if(dynamic_cast<NodeOperatorTwoArguments<T>*>(parent_of_leaf) != nullptr)
    {
        auto* res = dynamic_cast<NodeOperatorTwoArguments<T>*>(parent_of_leaf);
        delete res->left;
        res->left = other.root->clone();
    }
    return result;
}

template<typename T>
ExpressionTree<T>& ExpressionTree<T>::operator=(ExpressionTree<T> other)
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

template<>
bool ExpressionTree<std::string>::isNumber(const std::string &token)
{
    if(token[0] == '\"' && token[token.size() - 1] == '\"')
    {
        return true;
    }
    else return false;
}


template<typename T>
bool ExpressionTree<T>::isOperatorOneArgument(const std::string &token)
{
    return token == SIN || token == COS;
}

template<typename T>
void ExpressionTree<T>::initializeVariables(std::unordered_map<std::string,T> &expression)
{
    if(root != nullptr) initializeVariablesRecursive(root, expression);
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
    if(root == nullptr) return "";
    std::vector<std::string> vars;
    createVariables(root, vars);
    std::set<std::string> uniqueVars;
    std::string result;
    for(const std::string& var : vars) {
        if(uniqueVars.find(var) == uniqueVars.end()) {
            result += var + " ";
            uniqueVars.insert(var);
        }
    }
    if (!result.empty()) result.pop_back();
    return result;
}


template<typename T>
int ExpressionTree<T>::getVariablesCount() const
{
    if (root == nullptr) return 0;
    std::vector<std::string> vars;
    createVariables(root, vars);
    std::unordered_set<std::string> vars_set(vars.begin(), vars.end());
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
    if(root == nullptr) return "";
    std::string result;
    printTreeStructureRecursive(root, 0, result);
    return result;
}

template<typename T>
bool ExpressionTree<T>::isEmpty() const
{
    return root == nullptr;
}

template<typename T>
bool ExpressionTree<T>::isNumber(const std::string& token)
{
    if (token.empty())
        return false;

    bool hasDot = false;

    for (char c : token)
    {
        if (!std::isdigit(c))
        {
            if (c == '.' && !hasDot)
            {
                hasDot = true;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}


////////////////////////////////////////////////////////////////////////////////////////
template<>
bool ExpressionTree<int>::isNumber(const std::string& token)
{
    return std::all_of(token.begin(), token.end(), ::isdigit);
}


template<>
Node<std::string>* ExpressionTree<std::string>::createTreeRecursive(std::vector<std::string>& expression, bool& ifError)
{
    if (expression.empty())
    {
        ifError = false;
        std::string none = "1";
        return new NodeConstant<std::string>(none);
    }
    std::string token = expression.front();
    expression.erase(expression.begin());
    if (isOperatorTwoArgument(token))
    {
        Node<std::string>* left = createTreeRecursive(expression, ifError);
        Node<std::string>* right = createTreeRecursive(expression, ifError);
        return new NodeOperatorTwoArguments(token, left, right);
    }
    else if (isOperatorOneArgument(token))
    {
        Node<std::string>* child = createTreeRecursive(expression, ifError);
        return new NodeOperatorOneArgument(token, child);
    }
    else if (isNumber(token))
    {
        return new NodeConstant<std::string>(token.substr(1, token.size() - 2));
    }
    else
    {
        return new NodeVariable<std::string>(token, "");
    }
}