#include "../../include/ExpressionTreeHeaders/Node.h"
#include <vector>
#include <iostream>

Node::Node() : data("") {children = std::vector<Node*>();}

Node::Node(std::string data) : data(data) {children = std::vector<Node*>();}

Node::Node(const Node& other) : data(other.data), value(other.value)
{
        for (Node* child : other.children) {
            children.push_back(new Node(*child));
        }
}

Node::~Node()
{
    for(Node* child : children)
    {
        delete child;
    }
}


void Node::create_children(int amount)
{
    for(int i = 0; i < amount; i++)
    {
        children.push_back(new Node());
    }
}


void Node::setData(std::string data_a)
{
    this->data = data_a;
}



Node* Node::get_child(int index) const
{
    if(index < children.size())
    {
        return children[index];
    }
    else
    {
        return nullptr;
    }
}

std::string Node::to_string() const
{
    return data;
}

std::string& Node::pass_data(){
    return data;
}







