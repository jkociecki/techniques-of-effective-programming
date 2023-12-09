#include "../include/StringUtils.h"
#include <sstream>

std::vector<std::string> split_by_whitespace(std::string& str)
{
    std::vector<std::string> tokens;
    std::istringstream iss(str);

    while (iss >> std::skipws >> std::ws)
    {
        std::string word;
        iss >> word;

        size_t endPos = word.find_last_not_of(" \t\r\n");
        if (endPos != std::string::npos)
        {
            word = word.substr(0, endPos + 1);
        }
        tokens.push_back(word);
    }
    return tokens;
}