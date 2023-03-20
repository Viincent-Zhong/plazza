/*
** EPITECH PROJECT, 2022
** Project Plazza
** File description:
** Plazza.cpp
*/

#include <iostream>
#include "Plazza.hpp"
#include "ParseParams.hpp"
#include "Reception.hpp"
#include "Prompt.hpp"

Plazza::Plazza()
{
}

Plazza::~Plazza()
{
}

bool Plazza::run(int ac, char **av)
{
    ParseParams params;
    Prompt reception;

    try {
        params.getParams(ac, av);
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    try {
        reception.run(params);
    } catch (std::domain_error &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return true;
}
