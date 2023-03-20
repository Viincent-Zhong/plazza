/*
** EPITECH PROJECT, 2022
** Project Plazza
** File description:
** ParseParams.cpp
*/

#include <stdexcept>
#include "ParseParams.hpp"
#include "Lib.hpp"

ParseParams::ParseParams()
{
}

ParseParams::~ParseParams()
{
}

void ParseParams::getParams(int ac, char **av)
{
    Lib lib;

    if (ac != NB_ARG)
        throw std::invalid_argument("wrong nbr of arguments");
    for (unsigned int i = 0; i != ac; ++i)
        if (!lib.isNumber(av[i]))
            throw std::invalid_argument("Bad argument, only positiv numbers");
    this->_mulCookingTime = std::stoi(av[0]);
    this->_nbCooks = std::stoi(av[1]);
    this->_timeReplaceIngredient = std::stoi(av[2]);
}

unsigned int ParseParams::getCookingTime() const
{
    return this->_mulCookingTime;
}

unsigned int ParseParams::getNbCooks() const
{
    return this->_nbCooks;
}

unsigned int ParseParams::getTimeIngredient() const
{
    return this->_timeReplaceIngredient;
}

