/*
** EPITECH PROJECT, 2022
** Project plazza
** File description:
** Reception.cpp
*/

#include <stdexcept>
#include <memory>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <regex>
#include "Kitchen.hpp"
#include "Reception.hpp"

Reception::Reception()
{
    this->_idCommand = 0;
    this->_idKitchen = 0;
}

Reception::~Reception()
{
    for (auto const &elem : this->_kitchens)
        elem.second.second.get()->destroyFifo();
    this->_kitchens.clear();
}

void Reception::init(ParseParams const &params)
{
    this->_params = params;
}

void Reception::initKitchen()
{
    std::shared_ptr<IPC> ipc = std::make_shared<IPC>(IPC(PATH_FILE + std::to_string(this->_idKitchen)));
    pid_t pid = fork();

    if (pid == -1)
        throw std::domain_error("Fork failed");
    else if (pid == 0) {
        Kitchen kitchen(this->_params.getNbCooks(),
        this->_params.getCookingTime(), this->_params.getTimeIngredient(), ipc);
        kitchen.run();
    } else {
        this->_kitchens.insert({this->_idKitchen, {pid, ipc}});
        this->_idKitchen++;
    }
}
