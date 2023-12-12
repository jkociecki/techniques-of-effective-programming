#include <iostream>
#include "inclulde//CTree.h"

int main()
{
    CTree tree("* 8 + 3 cos 0");
    double value = tree.evaluate();
    std::cout << value << std::endl;

    return 0;
}
