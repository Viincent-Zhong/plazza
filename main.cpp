/*
** EPITECH PROJECT, 2022
** Project Plazza
** File description:
** main.cpp
*/

#include <iostream>
#include "Plazza.hpp"

static const int help(void)
{
    std::cout << "USAGE:\n";
    std::cout << "\t./plazza [multipliers] [cooks] [time]\n";
    std::cout << "DESCRIPTION:\n";
    std::cout << "\tmultipliers: multiplier for cooking time\n";
    std::cout << "\tcooks: number of cooks per kitchen\n";
    std::cout << "\ttime: time in milliseconds, time for the kitchen to replace ingredients\n";
    return 0;
}

int main(int ac, char **av)
{
    std::string entry;
    Plazza plazza;

    if (ac == 2) {
        entry = av[1];
        if (entry == "-h" || entry == "--help")
            return help();
    }
    if (!plazza.run(ac - 1, av + 1))
        return 84;
    return 0;
}