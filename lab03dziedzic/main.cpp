#include <iostream>
#include <vector>
#include "inclulde/CTree.h"

int main()
{
    std::string expression = "+ * 5 sin x * + a b 8";
    CTree tree(expression);
    double value = tree.evaluate();
    std::cout << value << std::endl;
    std::vector<std::string> variables = {"1", "2", "3"};
    tree.initializeVariables(tree.root, variables);
    std::cout << tree.evaluate() << std::endl;

    return 0;
}
