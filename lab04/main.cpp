#include <iostream>
#include <vector>
#include "inclulde/CTree.h"

int main()
{
//    std::string expression = "+ * 5 sin x * + a b 8";
//    CTree tree(expression);
//    double value = tree.evaluate();
//    std::cout << value << std::endl;
//    std::vector<std::string> variables = {"1", "2", "3"};
//    tree.initializeVariablesRecursive(tree.root, variables);
//    std::cout << tree.evaluate() << std::endl;

    std::vector<std::string> variables = {"1", "2"};

    std::string expression = "+ + + +";
    std::string expression2 = "* 3 4";
    CTree tree1(expression);
    CTree tree2(expression2);
    CTree result = tree1 + tree2;
    std::cout << result.toString();


    return 0;
}
