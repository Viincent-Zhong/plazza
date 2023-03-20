/*
** EPITECH PROJECT, 2022
** Project plazza
** File description:
** Lib.cpp
*/

#include <fstream>
#include "Lib.hpp"

Lib::Lib()
{
}

Lib::~Lib()
{
}

std::string Lib::getDataFile(std::string const &file)
{
    std::ifstream ifs(file);
    std::string content((std::istreambuf_iterator<char>(ifs)),
                        (std::istreambuf_iterator<char>()));
    return content;
}

void Lib::splitString(std::string str, std::vector<std::string> &list, char const &c)
{	
    std::string token;
    size_t pos;

    while ((pos = str.find(c)) != std::string::npos) {
        token = str.substr(0, pos);
        list.push_back(token);
        str.erase(0, pos + 1);
    }
    if (!str.empty())
        list.push_back(str);
}

bool Lib::goodChar(std::string const &str)
{
    for (auto const &c : str)
        if (c < 'A' || c > 'Z' && c < 'a' || c > 'z')
            return false;
    return true;
}

bool Lib::isNumber(std::string const &str)
{
    if (str.size() == 0)
        return false;
    for (unsigned int i = 0; str[i] != '\0'; ++i)
        if (std::isdigit(str[i]) == 0)
            return false;
    return true;
}

bool Lib::writeToFile(std::string const &path, std::string const &data)
{
    std::ofstream file;

    file.open(path.c_str(), std::istream::out | std::ifstream::trunc);
    if (!file.is_open() || file.fail())
        return false;
    file << data;
    file.close();
    return true;
}
