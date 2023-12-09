#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>


class ExpressionTree {

private:
    bool is_initialized;
    Node* root;

    Node* get_parent_of_leaf(Node* root, Node* parent) const;

    double evaluate_tree_recursive(const Node* root) const;

    void create_tree(std::vector<std::string>& tokens, Node* root, bool& if_error);
    void create_prefix(const Node* root, std::string& result) const;
    void create_vars(const Node* root, std::set<std::string>& result) const;
    void initialize_vars_recursive(const std::unordered_map<std::string, int>& values, Node* root) const;
    void printTreeStructure(const Node* root_a, int level) const;

    static bool is_variable(const std::string& str);
    static bool is_2arg_op(const std::string& op);
    static bool is_1arg_op(const std::string& op);
    static bool is_number(const std::string& str);

public:

    explicit ExpressionTree(std::vector<std::string>& tokens);
    ExpressionTree(const ExpressionTree& tree);
    ExpressionTree();
    ~ExpressionTree();

    [[nodiscard]] std::string to_string() const;
    [[nodiscard]] std::string vars_to_string() const;

    [[nodiscard]] double evaluate_tree() const;
    [[nodiscard]] int get_variables_count() const;
    [[nodiscard]] bool is_initialized_vars() const;
    void initialize_vars(const std::unordered_map<std::string, int>& values);
    void printTreeStructure() const;

    ExpressionTree operator+(const ExpressionTree& tree) const;
    ExpressionTree& operator=(const ExpressionTree& tree);
};

const std::string DIVISION = "/";
const std::string MULTIPLICATION = "*";
const std::string ADDITION = "+";
const std::string SUBSTRUCTION = "-";
const std::string SIN = "sin";
const std::string COS = "cos";
const std::string SUPERSUM = "++";


static const std::set<std::string> OPERATORS_TWO_ARGUEMNTS = {DIVISION, MULTIPLICATION, ADDITION, SUBSTRUCTION};
static const std::set<std::string> OPERATORS_ONE_ARGUEMNT = {SIN, COS};

#endif // TREE_H
