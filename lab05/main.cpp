#include <iostream>
#include <vector>
#include <memory>
#include "inclulde/ExpressionTree/ExpressionTree.h"
#include "inclulde/UI.h"

int main()
{
    ExpressionTree<int> result;


    ExpressionTree<int> tree("+ 1 2");
    ExpressionTree<int> tree2("* 3 4");
    ExpressionTree<int> tree3("+ 5 6");


    result = tree + tree2 + tree3;
    std::cout << result.evaluate() << std::endl;
    std::cout << tree.evaluate() << std::endl;
    std::cout << tree2.evaluate() << std::endl;
    std::cout << tree3.evaluate() << std::endl;

    result = ExpressionTree<int>("+ 1 2") + ExpressionTree<int>("* 3 4") + ExpressionTree<int>("+ 5 6");
//    std::cout << result.evaluate() << std::endl;

    UI<int> ui;
    ui.run();
}
