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
                ExpressionTree<T> tempTree(remainingInput);
                currentTree = std::move(tempTree);
                remainingInput = "";
            }
            else std::cout << EMPTY_EXP_PROMPT;
        }
        else if(command == VARS)
        {
            handleVars();
            remainingInput = "";
        }
        else if(command == PRINT)
        {
            handlePrint();
            remainingInput = "";
        }
        else if(command == COMP)
        {
            handleComp(remainingInput);
            remainingInput = "";
        }
        else if(command == JOIN)
        {
            handleJoin(remainingInput);
            remainingInput = "";
        }
        else if(command == SWITCH)
        {
            handleTypes();
            remainingInput = "";
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
void UI<T>::handleJoin(std::string remainingInput)
{
    currentTree = currentTree + ExpressionTree<T>(remainingInput);
    std::cout << currentTree.treeStructure() << std::endl;
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


template<typename T>
void UI<T>::handleComp(std::string remainingInput)
{
    std::vector<std::string> evaluation = split_by_whitespace(remainingInput);
    std::string keys = currentTree.varsToString();
    std::vector <std::string> variables = split_by_whitespace(keys);
    std::unordered_map<std::string, T> valuesOfVars;
    if(!evaluation.empty() && currentTree.getVariablesCount() == evaluation.size() && !currentTree.isEmpty())
    {
        try
        {
            for(int i = 0; i < variables.size(); i++)
            {
             valuesOfVars[variables[i]] = std::stod(evaluation[i]);
            }
            currentTree.initializeVariables(valuesOfVars);
            std::cout << RESULT <<currentTree.evaluate() << std::endl;
        }
        catch (std::invalid_argument& e)
        {
            std::cout << CHECK_VARS_PROMPT << std::endl;
        }
    }
    else if(currentTree.getVariablesCount() == 0 && !currentTree.isEmpty()) std::cout << RESULT <<currentTree.evaluate() << std::endl;
    else std :: cout << CHECK_VARS_PROMPT << std::endl;
}


template<>
void UI<std::string>::handleComp(std::string remainingInput)
{
    std::vector<std::string> evaluation = split_by_whitespace(remainingInput);
    std::string keys = currentTree.varsToString();
    std::vector <std::string> variables = split_by_whitespace(keys);
    std::unordered_map<std::string, std::string> valuesOfVars;
    if(!evaluation.empty() && currentTree.getVariablesCount() == evaluation.size() && !currentTree.isEmpty() && remainingInput != "")
    {
        for(int i = 0; i < variables.size(); i++)
        {
            valuesOfVars[variables[i]] = evaluation[i];
        }
        currentTree.initializeVariables(valuesOfVars);
        std::cout << RESULT <<currentTree.evaluate() << std::endl;
        remainingInput = "";
    }
    else if(currentTree.getVariablesCount() == 0 && !currentTree.isEmpty()) std::cout << RESULT <<currentTree.evaluate() << std::endl;
    else std :: cout << CHECK_VARS_PROMPT << std::endl;
}