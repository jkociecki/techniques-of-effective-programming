#include <iostream>
#include <vector>



class Node{
private:
    std::string data;
    std::vector<Node*> children;
    int value;

    Node();
    explicit Node(std::string data);
    Node(const Node& node);
    ~Node();

    Node* get_child(int index) const;

    std::string& pass_data();
    std::string to_string() const;

    void create_children(int amount);
    void setData(std::string data);

    friend class ExpressionTree;
};