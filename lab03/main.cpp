#include <iostream>
#include "include/ExpressionTreeHeaders/ExpressionTree.h"
#include "include/StringUtils.h"
#include "include/UI.h"

int main() {
    std::vector<std::string> tokens1 = {"+", "*", "5", "cos", "0", "*", "+", "4", "1", "8"};
    std::vector<std::string> tokens2 = {"+", "3", "-", "6", "2"};
    std::vector<std::string> tokens3 = {"+", "2", "-", "6", "4"};

    ExpressionTree tree1 = ExpressionTree(tokens1);
    ExpressionTree tree2 = ExpressionTree(tokens2);
    ExpressionTree tree3 = ExpressionTree(tokens3);

    ExpressionTree result = tree2 + tree3;
    ExpressionTree result2 = tree1 + result;
    std::cout << result.evaluate_tree() << std::endl;
    std::cout << result2.evaluate_tree() << std::endl;
    std::cout << "REST IN UI" << std::endl << std::endl;





    run();
    return 0;
}
