#include <iostream>
#include <vector>

std::vector<std::string> split_by_whitespace(std::string& str);
void extractFirstWord(const std::string& input, std::string& command, std::string& remainingInput);
std::string operator*(const std::string& str1, const std::string& str2);
std::string operator/(const std::string& str1, const std::string& str2);
std::string operator-(const std::string& str1, const std::string& str2);
std::string toUpper(const std::string& str);
std::string toLower(const std::string& str);