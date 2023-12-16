//#include "../inclulde/UI.h"
//#include "../inclulde/StringUtils.h"
//#include "../inclulde/ExpressionTree.h"
//
//
//void UI::run()
//{
//
//    std::cout << STARTING_PROMPT << std::endl;
//    std::string input;
//    std::getline(std::cin, input);
//    std::string command, remainingInput;
//    extractFirstWord(input, command, remainingInput);
//
//    while (command != EXIT)
//    {
//        if (command == ENTER)
//        {
//            if (remainingInput.size() > 0)
//            {
//                currentTree = ExpressionTree<int>(remainingInput);
//
//            }
//            else
//            {
//                std::cout << EMPTY_EXP_PROMPT;
//            }
//        }
//        else if (command == VARS)
//        {
//            std::cout << currentTree.varsToString() << std::endl;
//        }
//        else if (command == PRINT)
//        {
//            std::cout << currentTree.toString() << std::endl;
//        }
//        else if (command == JOIN)
//        {
//            if (!remainingInput.empty())
//            {
//                // Użyj odpowiedniego typu danych na podstawie wyboru użytkownika
//                ExpressionTree toJoin;
//                if (dataType == "int")
//                {
//                    toJoin = ExpressionTree<int>(remainingInput);
//                }
//                else if (dataType == "double")
//                {
//                    toJoin = ExpressionTree<double>(remainingInput);
//                }
//                else if (dataType == "float")
//                {
//                    toJoin = ExpressionTree<float>(remainingInput);
//                }
//
//                currentTree = currentTree + toJoin;
//                std::cout << currentTree.treeStructure() << std::endl;
//            }
//            else
//            {
//                std::cout << EMPTY_EXP_PROMPT << std::endl;
//            }
//        }
//        else if (command == COMP)
//        {
//            std::vector<std::string> evaluation = split_by_whitespace(remainingInput);
//            if (!evaluation.empty() && currentTree.getVariablesCount() == evaluation.size())
//            {
//                std::vector<double> values;
//                try
//                {
//                    for (int i = 0; i < evaluation.size(); i++)
//                    {
//                        values.push_back(std::stod(evaluation[i]));
//                    }
//                    currentTree.initializeVariables(values);
//                    std::cout << RESULT << currentTree.evaluate() << std::endl;
//                }
//                catch (std::invalid_argument& e)
//                {
//                    std::cout << CHECK_VARS_PROMPT;
//                }
//            }
//            else if (currentTree.getVariablesCount() == 0)
//            {
//                std::cout << RESULT << currentTree.evaluate() << std::endl;
//            }
//            else
//            {
//                std::cout << CHECK_VARS_PROMPT;
//            }
//        }
//        else
//        {
//            std::cout << INVALID_CMD_PROMPT << std::endl;
//        }
//
//        std::cout << "Do you want to change the data type? (yes/no): ";
//        std::string changeType;
//        std::cin >> changeType;
//        if (changeType == "yes")
//        {
//            std::cout << "Choose new data type (int, double, float, string): ";
//            std::cin >> dataType;
//
//            while (dataType != "int" && dataType != "double" && dataType != "float" && dataType != "string")
//            {
//                std::cout << "Invalid data type. Please choose again: ";
//                std::cin >> dataType;
//            }
//
//            // Utwórz nowy obiekt ExpressionTree na podstawie nowego wyboru użytkownika
//            if (dataType == "int")
//            {
//                currentTree = ExpressionTree<int>();
//            }
//            else if (dataType == "double")
//            {
//                currentTree = ExpressionTree<double>();
//            }
//            else if (dataType == "float")
//            {
//                currentTree = ExpressionTree<float>();
//            }
//            else if (dataType == "string")
//            {
//                currentTree = ExpressionTree<std::string>();
//            }
//        }
//
//        std::cout << STARTING_CMD;
//        std::getline(std::cin, input);
//        extractFirstWord(input, command, remainingInput);
//    }
//}
