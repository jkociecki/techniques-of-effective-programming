#include "../inclulde/UI.h"
#include "../inclulde/StringUtils.h"
#include "../inclulde/CTree.h"

void UI::run()
{
    std::cout << STARTING_PROMPT << std::endl;
    std::string input;
    std::getline(std::cin, input);
    std::string command, remainingInput;
    extractFirstWord(input, command, remainingInput);

    while(command != EXIT)
    {
        if(command == ENTER)
        {
            if(remainingInput.size() > 0)
            {
                currentTree = CTree(remainingInput);
            }
            else std::cout << EMPTY_EXP_PROMPT << std::endl;
        }

        else if(command == VARS)
        {
              std::cout << currentTree.varsToString() << std::endl;
        }

        else if(command == PRINT)
        {
            std::cout << currentTree.toString() << std::endl;
        }

        else if(command == JOIN)
        {
            if(!remainingInput.empty())
            {
                CTree toJoin = CTree(remainingInput);
                currentTree = currentTree + toJoin;
                std::cout << currentTree.treeStructure() << std::endl;
            }
            else std::cout << EMPTY_EXP_PROMPT << std::endl;
        }

        else if(command == COMP)
        {
            std::vector<std::string> evaluation = split_by_whitespace(remainingInput);
            std::cout << evaluation.size() << " = " << currentTree.getVariablesCount() << std::endl;
            if(!evaluation.empty() && currentTree.getVariablesCount() == evaluation.size())
            {
                std::vector<double> values;
                try
                {
                    for(int i = 0; i < evaluation.size(); i++)
                    {
                        values.push_back(std::stod(evaluation[i]));
                    }
                    currentTree.initializeVariables(values);
                    std::cout << RESULT <<currentTree.evaluate() << std::endl;
                }
                catch (std::invalid_argument& e)
                {
                    std::cout << CHECK_VARS_PROMPT;
                }
            }
            else if(currentTree.getVariablesCount() == 0) std::cout << RESULT <<currentTree.evaluate() << std::endl;
            else std :: cout << CHECK_VARS_PROMPT;
        }

        else std::cout << INVALID_CMD_PROMPT << std::endl;

        std::cout << STARTING_CMD << std::endl;
        std::getline(std::cin, input);
        extractFirstWord(input, command, remainingInput);

    }
}
