#include <iostream>

void run();

//commands
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