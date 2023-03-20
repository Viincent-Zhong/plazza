/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** CommandParsing
*/

#include <regex>
#include <string>
#include "Parser.hpp"

bool Parser::Contain(std::string const &str, std::string const &regex)
{
    std::regex search(regex);
    std::smatch match;

    if (str.size() == 0)
        return false;
    if (std::regex_search(str, match, search)) {
    } else
        return false;
    return true;
}