#include "../../include/ExpressionTreeHeaders/ExpressionTree.h"
#include <iostream>
#include <unordered_map>
#include <cmath>
#include <queue>

ExpressionTree::ExpressionTree(std::vector<std::string>& tokens)
{
    root = new Node();
    is_initialized = false;
    bool if_error = false;
    create_tree(tokens, root, if_error);
    if (if_error || !tokens.empty())
    {
        std::cout << "CORRECTED EXPRESSION: " << to_string() << std::endl;
    }
}

ExpressionTree::ExpressionTree()
{
    is_initialized = false;
    root = new Node();
}

ExpressionTree::ExpressionTree(const ExpressionTree& tree)
{
    is_initialized = tree.is_initialized;
    root = new Node(*tree.root);
}

ExpressionTree::~ExpressionTree()
{
    delete root;
}

// NOLINTNEXTLINE
void ExpressionTree::create_tree(std::vector<std::string>& tokens, Node* root_a, bool& if_error)
{
    if (tokens.empty())
    {
        root_a->setData("1");
        root_a->value = 1;
        if_error = true;
        return;
    }
    std::string data = tokens.front();
    tokens.erase(tokens.begin());

    if (is_1arg_op(data))
    {
        root_a->setData(data);
        root_a->create_children(1);
        create_tree(tokens, root_a->get_child(0), if_error);
    }
    else if (is_2arg_op(data))
    {
        root_a->setData(data);
        root_a->create_children(2);
        create_tree(tokens, root_a->get_child(0), if_error);
        create_tree(tokens, root_a->get_child(1), if_error);
    }
    else if ((is_number(data) || is_variable(data)))
    {
        if (is_number(data)) root_a->value = std::stoi(data);
        root_a->setData(data);
    }
    else
    {
        std::cout << "ERROR: " << data << " is not a number or operator" << std::endl;
    }

}

// NOLINTNEXTLINE
double ExpressionTree::evaluate_tree_recursive(const Node* root_a) const
{
    if (root_a != nullptr)
    {
        if (is_1arg_op(root_a->data))
        {
            double l_value = evaluate_tree_recursive(root_a->get_child(0));
            if (root_a->data == SIN) return sin(l_value);
            else if (root_a->data == COS) return cos(l_value);
        }
        else if (is_2arg_op(root_a->data))
        {
            double l_value = evaluate_tree_recursive(root_a->get_child(0));
            double r_value = evaluate_tree_recursive(root_a->get_child(1));

            if (root_a->data == ADDITION) return l_value + r_value;
            else if (root_a->data == SUBSTRUCTION) return l_value - r_value;
            else if (root_a->data == MULTIPLICATION) return l_value * r_value;
            else if (root_a->data == DIVISION)
            {
                if (r_value == 0) throw std::invalid_argument("pamietaj cholero");
                else return l_value / r_value;
            }
        }
        else if(is_number(root_a->data) || is_variable(root_a->data))
        {
            return root_a->value;
        }
    }
    return 0;
}

double ExpressionTree::evaluate_tree() const
{
    return evaluate_tree_recursive(root);
}

// NOLINTNEXTLINE
Node* ExpressionTree::get_parent_of_leaf(Node* root_a, Node* parent) const
{
    if (root_a != nullptr)
    {
        if (root_a->get_child(0) == nullptr && root_a->get_child(1) == nullptr)
        {
            return parent;
        }
        else
        {
            Node* left = get_parent_of_leaf(root_a->get_child(0), root_a);
            Node* right = get_parent_of_leaf(root_a->get_child(1), root_a);
            if (left != nullptr) return left;
            else return right;
        }
    }
    else return nullptr;
}


ExpressionTree ExpressionTree::operator+(const ExpressionTree& tree) const
{
    ExpressionTree result = ExpressionTree(*this);
    Node* result_parent = result.get_parent_of_leaf(result.root, nullptr);
    Node* second_tree_node = new Node(*tree.root);
    if (is_variable(result_parent->get_child(0)->data))
    {
        delete result_parent->children.at(0);
        result_parent->children.at(0) = second_tree_node;
    }
    else
    {
        delete result_parent->children.at(1);
        result_parent->children.at(1) = second_tree_node;
    }

    return result;
}

ExpressionTree& ExpressionTree::operator=(const ExpressionTree& tree)
{
    if (this != &tree)
    {
        delete root;
        root = new Node(*tree.root);
    }
    return *this;
}

// NOLINTNEXTLINE
void ExpressionTree::create_prefix(const Node* const root_a, std::string& result) const
{
    if (root_a != nullptr)
    {
        result += " " + root_a->to_string();
        create_prefix(root_a->get_child(0), result);
        create_prefix(root_a->get_child(1), result);
    }
}

// NOLINTNEXTLINE
void ExpressionTree::create_vars(const Node* root_a, std::set<std::string>& result) const
{
    if (root_a != nullptr)
    {
        if (!is_1arg_op(root_a->to_string()) && !is_2arg_op(root_a->to_string()) && !is_number(root_a->to_string()))
        {
            result.insert(root_a->to_string());
        }
        create_vars(root_a->get_child(0), result);
        create_vars(root_a->get_child(1), result);
    }
}

std::string ExpressionTree::to_string() const
{
    std::string result;
    create_prefix(root, result);
    return result;
}

std::string ExpressionTree::vars_to_string() const
{
    std::set<std::string> vars;
    create_vars(root, vars);
    std::string result;
    for (const std::string& str : vars)
    {
        result += str + " ";
    }
    if (!result.empty())
    {
        result.pop_back();
    }
    return result;
}

// NOLINTNEXTLINE
void ExpressionTree::initialize_vars_recursive(const std::unordered_map<std::string, int>& values, Node* root) const
{
    if (root != nullptr) {
        if (!is_1arg_op(root->pass_data()) && !is_2arg_op(root->pass_data()) && !is_number(root->pass_data()))
        {
            std::unordered_map<std::string, int>::const_iterator it = values.find(root->data);
            if (it != values.end()) root->value = it->second;
        }
        if (root->get_child(0) != nullptr)
        {
            initialize_vars_recursive(values, root->get_child(0));
        }
        if (root->get_child(1) != nullptr)
        {
            initialize_vars_recursive(values, root->get_child(1));
        }
    }
}

void ExpressionTree::initialize_vars(const std::unordered_map<std::string, int>& values)
{
    if(this->get_variables_count() == values.size())
    {
        is_initialized = true;
    }
    initialize_vars_recursive(values, root);
}

int ExpressionTree::get_variables_count() const
{
    std::set<std::string> vars;
    create_vars(root, vars);
    return vars.size();
}

// NOLINTNEXTLINE
void ExpressionTree::printTreeStructure(const Node* root_a, int level) const
{
    if (root_a != nullptr)
    {
        for (int i = 0; i < level; ++i)
        {
            std::cout << "  ";
        }
        std::cout << "|--" << root_a->to_string() << std::endl;
        printTreeStructure(root_a->get_child(0), level + 1);
        printTreeStructure(root_a->get_child(1), level + 1);
    }
}

void ExpressionTree::printTreeStructure() const
{
    printTreeStructure(root, 0);
}

bool ExpressionTree::is_initialized_vars() const
{
    if(get_variables_count() == 0) return true;
    else return is_initialized;
}



bool ExpressionTree::is_1arg_op(const std::string& op)
{
    for (const std::string& str : OPERATORS_ONE_ARGUEMNT)
    {
        if (str == op) return true;
    }
    return false;
}

bool ExpressionTree::is_2arg_op(const std::string& op)
{
    for (const std::string& str : OPERATORS_TWO_ARGUEMNTS)
    {
        if (str == op) return true;
    }
    return false;
}

bool ExpressionTree::is_variable(const std::string& str)
{
    return !is_1arg_op(str) && !is_2arg_op(str);
}

bool ExpressionTree::is_number(const std::string& str)
{
    for (char c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}




//void ExpressionTree::printTreeStructureByLevels(const Node *root_a) const {
//    if (root_a == nullptr) {
//        return;
//    }
//
//    std::queue<const Node*> nodesQueue;
//    nodesQueue.push(root_a);
//
//    while (!nodesQueue.empty()) {
//        const Node* current = nodesQueue.front();
//        nodesQueue.pop();
//
//        std::cout << current->to_string() << " ";
//
//        if (current->get_child(0) != nullptr) {
//            nodesQueue.push(current->get_child(0));
//        }
//
//        if (current->get_child(1) != nullptr) {
//            nodesQueue.push(current->get_child(1));
//        }
//    }
//
//    std::cout << std::endl;
//}
