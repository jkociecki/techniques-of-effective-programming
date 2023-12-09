#include "../include/UI.h"
#include "../include/StringUtils.h"
#include "../include/ExpressionTreeHeaders/ExpressionTree.h"
#include <iostream>
#include <vector>
#include <unordered_map>

void run() {

    std::cout << STARTING_PROMPT << std::endl;
    ExpressionTree tree;
    std::cout << STARTING_CMD;
    std::string input;
    std::getline(std::cin, input);
    std::vector<std::string> tokens = split_by_whitespace(input);
    std::string command = tokens[0];

    while (command != EXIT)
    {
        if (command == ENTER)
        {
            if (tokens.size() > 1)
            {
                tokens.erase(tokens.begin());
                tree = ExpressionTree(tokens);
            }
            else std::cout << EMPTY_EXP_PROMPT << std::endl;

        }

        else if (command == VARS)
        {
            std::cout << tree.vars_to_string() << "\n";
        }

        else if (command == PRINT)
        {
            std::cout << tree.to_string() << std::endl;

        }

        else if (command == JOIN)
        {
            if (tokens.size() > 1)
            {
                tokens.erase(tokens.begin());
                ExpressionTree to_join = ExpressionTree(tokens);
                tree = tree + to_join;
                tree.printTreeStructure();
            }
            else std::cout << EMPTY_EXP_PROMPT<< std::endl;

        }

        else if (command == COMP)
        {
            if (tokens.size() > 1)
            {
                tokens.erase(tokens.begin());
                std::string keys = tree.vars_to_string();
                std::vector<std::string> variables = split_by_whitespace(keys);
                std::unordered_map<std::string, int> values_of_vars;

                if (variables.size() == tokens.size())
                {
                    try
                    {
                        for (int i = 0; i < variables.size(); i++)
                        {
                            values_of_vars[variables[i]] = std::stoi(tokens[i]);
                        }
                    }
                    catch(const std::invalid_argument& e) {
                        std::cout << "PARSING ERROR" << std::endl;

                    }
                    tree.initialize_vars(values_of_vars);

                    if (tree.is_initialized_vars())
                    {
                        std::cout <<  RESULT << tree.evaluate_tree() << std::endl;
                    }
                    else std::cout << CHECK_VARS_PROMPT << std::endl;

                }
                else std::cout << CHECK_VARS_PROMPT << std::endl;
            }
            else
            {

                if (tree.is_initialized_vars())
                {
                    std::cout << RESULT << tree.evaluate_tree() << std::endl;
                }
                else std::cout << CHECK_VARS_PROMPT << std::endl;
            }

        }
        else std::cout << INVALID_CMD_PROMPT << std::endl;

        std::cout << STARTING_CMD;
        std::getline(std::cin, input);
        tokens = split_by_whitespace(input);
        command = tokens[0];
    }
}
