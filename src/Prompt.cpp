/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Prompt
*/

#include <iostream>
#include <string>
#include "ParseParams.hpp"
#include "SelectI.hpp"
#include "Prompt.hpp"

Prompt::Prompt()
{
}

Prompt::~Prompt()
{
}

void Prompt::run(ParseParams const &params)
{
    SelectI block(0, 3);
    std::string line;

    this->_reception.init(params);
    PromptDisplay::printPrompt();
    while (1) {
        if (block.Select() == -1)
            break;
        if (block.IsSet()) {
            if (!std::getline(std::cin, line))
                break;
            _reception.checkKitchenDeath();
            try {
                if (line.compare("status") == 0)
                    _reception.getStatus(line);
                else
                    _reception.sendCommand(line);
            } catch (std::invalid_argument &e) {
                std::cerr << e.what() << std::endl;
            }
            PromptDisplay::printPrompt();
        } else {
            _reception.checkKitchenDeath();
            _reception.checkOrders();
        }
    }
}
