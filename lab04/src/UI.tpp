template<typename T>
void UI<T>::run()
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
            if(!remainingInput.empty())
            {
                currentTree = ExpressionTree<T>(remainingInput);
                remainingInput = "";
            }
            else std::cout << EMPTY_EXP_PROMPT;
        }
        else if(command == VARS)
        {
            handleVars();
        }
        else if(command == PRINT)
        {
            handlePrint();
        }
        else if(command == COMP)
        {
            handleComp(remainingInput);
        }
        else if(command == JOIN)
        {
            handleJoin(remainingInput);
        }
        else if(command == SWITCH)
        {
            handleTypes();
        }

        else std::cout << INVALID_CMD_PROMPT << std::endl;

        std::cout << STARTING_CMD;
        std::getline(std::cin, input);
        extractFirstWord(input, command, remainingInput);

    }
}


template<typename T>
void UI<T>::handleVars()
{
    std::cout << currentTree.varsToString() << std::endl;
}

template<typename T>
void UI<T>::handlePrint()
{
    std::cout << currentTree.toString() << std::endl;
}

template<typename T>
void UI<T>::handleComp(std::string remainingInput)
{
    std::vector<std::string> evaluation = split_by_whitespace(remainingInput);
    if(!evaluation.empty() && currentTree.getVariablesCount() == evaluation.size())
    {
        std::vector<T> values;
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


template<typename T>
void UI<T>::handleJoin(std::string remainingInput)
{
    ExpressionTree toJoin = ExpressionTree<T>(remainingInput);
    currentTree = currentTree + toJoin;
    std::cout << currentTree.treeStructure() << std::endl;
}

template<>
void UI<std::string>::handleComp(std::string remainingInput)
{
    std::vector<std::string> evaluation = split_by_whitespace(remainingInput);
    std::cout << evaluation.size() << " " << currentTree.getVariablesCount() << std::endl;
    if(!evaluation.empty() && currentTree.getVariablesCount() == evaluation.size())
    {
        std::vector<std::string> values;
        try
        {
            for(int i = 0; i < evaluation.size(); i++)
            {
                values.push_back(evaluation[i]);
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

template<typename T>
void UI<T>::handleTypes()
{
    std::cout << "Please enter the data type you want to use: ";
    std::string dataType;
    std::getline(std::cin, dataType);
    if(dataType == "int")
    {
        UI<int> ui;
        ui.run();
    }
    else if(dataType == "double")
    {
        UI<double> ui;
        ui.run();
    }
    else if(dataType == "float")
    {
        UI<float> ui;
        ui.run();
    }
    else if(dataType == "string")
    {
        UI<std::string> ui;
        ui.run();
    }
    else std::cout << "Invalid data type. Please enter a valid data type \n";
}