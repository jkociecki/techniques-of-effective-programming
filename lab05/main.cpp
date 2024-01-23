#include <iostream>
#include <vector>
#include <memory>
#include "include/ExpressionTree/ExpressionTree.h"
#include "include/UI.h"
#include "my-pointer/MyArray2.h"
#include "my-pointer/SmartPointer.h"




int main()
{
    MyArray<int> array1(10);
    for (int i = 0; i < array1.size(); i++)
    {
        array1[i] = i * i;
    }

    MyArray<int> array2 = array1;
    array2[0] = 100;
    for (int i = 0; i < array2.size(); i++) {
        std::cout << array2[i] << " " << array1[i] << std::endl;
    }
    std::cout << std::endl;
    MyArray<int> array3 = std::move(array1);
    array3[1] = 70;
    std::cout << array3[1];

    return 0;
}

//int main()
//{
//
//    SmartPointer<int> ptr(new int(5));
//    SmartPointer<int> ptr2 = ptr;
//    std::cout << *ptr << std::endl;
//    std::cout << *ptr2 << std::endl;
//    ExpressionTree<int> result;
//    ExpressionTree<int> tree("+ 1 2");
//    ExpressionTree<int> tree2("* 3 4");
//    ExpressionTree<int> tree3("+ 5 6");
//
//
//    result = tree + tree2 + tree3;
//    std::cout << result.evaluate() << std::endl;
//    std::cout << tree.evaluate() << std::endl;
//    std::cout << tree2.evaluate() << std::endl;
//    std::cout << tree3.evaluate() << std::endl;
//    result = ExpressionTree<int>("+ 1 2") + ExpressionTree<int>("* 3 4") + ExpressionTree<int>("+ 5 6");
//    std::cout << result.evaluate() << std::endl;
//
//    UI<int> ui;
//    ui.run();
//}
