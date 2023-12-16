#include "../inclulde/StringUtils.h"
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

void extractFirstWord(const std::string& input, std::string& command, std::string& remainingInput)
{
    std::istringstream iss(input);
    iss >> command;
    std::getline(iss, remainingInput);
    remainingInput = remainingInput.substr(1);
}

std::string operator*(const std::string& str1, const std::string& str2)
{
    std::string result = "";
    char toBeReplaced = str2[0];
    for (char c : str1)
    {
        if (c == toBeReplaced)
        {
            result += str2;
        }
        else
        {
            result += c;
        }
    }
    return result;
}


std::string operator/(const std::string& str1, const std::string& str2)
{
    if (str2.empty()) return str1;
    std::string result = str1;
    size_t pos = result.find(str2);
    while (pos != std::string::npos) {
        result.replace(pos, str2.length(), 1, str2[0]);
        pos = result.find(str2, pos + 1);
    }
    return result;
}

std::string operator-(const std::string& str1, const std::string& str2)
{
    std::string result = str1;

    size_t pos = result.rfind(str2);
    if (pos != std::string::npos)
    {
        result.erase(pos, str2.length());
    }

    return result;
}

std::string toUpper(const std::string& str)
{
    std::string result = str;
    for (char& c : result)
    {
        c = toupper(c);
    }
    return result;
}

std::string toLower(const std::string& str)
{
    std::string result = str;
    for (char& c : result)
    {
        c = tolower(c);
    }
    return result;
}