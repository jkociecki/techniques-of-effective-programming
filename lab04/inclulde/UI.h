#include "ExpressionTree.h"
#include "StringUtils.h"
const std::string ENTER = "enter";
const std::string VARS = "vars";
const std::string PRINT = "print";
const std::string COMP = "comp";
const std::string JOIN = "join";
const std::string EXIT = "exit";


//prompts
const std::string STARTING_CMD = "ENTER COMMAND: \n";
const std::string EMPTY_EXP_PROMPT = "Error: Expression is empty. Please enter a valid expression \n";
const std::string CHECK_VARS_PROMPT = "Error: Please check the variables you entered \n";
const std::string INVALID_CMD_PROMPT = "Error: Invalid command. Please enter a valid command \n";
const std::string RESULT = "result: ";

const std::string STARTING_PROMPT = "AVAILABLE COMMANDS: \n"
                                    "ENTER <expression> - creates a new expression tree \n"
                                    "VARS - prints the variables in the expression tree \n"
                                    "PRINT - prints the expression tree in prefix notation \n"
                                    "COMP <value1> <value2> ... - computes the expression tree with the given values \n"
                                    "JOIN <expression> - joins the current expression tree with the given expression tree \n"
                                    "EXIT - exits the program \n";

template<typename T> class UI
{
public:
    UI() = default;
    void run();
    void handleVars();
    void handlePrint();
    void handleComp();
    void handleJoin();

    //static void handleTypes();
private:
ExpressionTree<T> currentTree;
};


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
            if(remainingInput.size() > 0)
            {
                currentTree = ExpressionTree<T>(remainingInput);
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
            handleComp();
        }
        else if(command == JOIN)
        {
            handleJoin();
    }
//        else if(command == "switch")
//        {
//            handleTypes();
//        }

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
void UI<T>::handleComp()
{
    std::string values;
    std::cout << "Please enter the values: ";
    std::getline(std::cin, values);
    std::vector<std::string> evaluation = split_by_whitespace(values);
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
void UI<T>::handleJoin()
{
    std::string expression;
    std::cout << "Please enter an expression: ";
    std::getline(std::cin, expression);
    ExpressionTree toJoin = ExpressionTree<T>(expression);
    currentTree = currentTree + toJoin;
    std::cout << currentTree.treeStructure() << std::endl;
}

template<>
void UI<std::string>::handleComp()
{
    std::string values;
    std::cout << "Please enter the values: ";
    std::getline(std::cin, values);
    std::vector<std::string> evaluation = split_by_whitespace(values);
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

//template<typename T>
// void UI<T>::handleTypes()
//{
//    std::cout << "Please enter the data type you want to use: ";
//    std::string dataType;
//    std::cin >> dataType;
//    if(dataType == "int")
//    {
//        UI<int> ui;
//        ui.run();
//    }
//    else if(dataType == "double")
//    {
//        UI<double> ui;
//        ui.run();
//    }
//    else if(dataType == "float")
//    {
//        UI<float> ui;
//        ui.run();
//    }
//    else std::cout << "Invalid data type. Please enter a valid data type \n";
//}