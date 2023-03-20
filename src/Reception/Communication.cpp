/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Communication
*/

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <regex>
#include "Parser.hpp"
#include "Reception.hpp"
#include "Display.hpp"

std::string communication(std::string const &str, std::shared_ptr<IPC> &ipc)
{
    std::string response;

    ipc << str;
    ipc >> response;
    return response;
}

void Reception::getStatus(std::string const &str)
{
    Display display;
    int status;

    for (auto it = this->_kitchens.begin(); it != this->_kitchens.end(); ++it) {
        if (waitpid(it->second.first, &status, WNOHANG) == 0) {
            std::cout << "Kitchen n°: " << it->first << "\n";
            display.displayStatus(communication(str, it->second.second), _listCommand);
        } else {
            it = this->_kitchens.erase(it);
            if (it == this->_kitchens.end())
                break;
        }
    }
    std::cout << this->_kitchens.size() << " kitchen(s) running\n";
}

bool Reception::kitchenTookCommand(std::string &cmd, std::vector<unsigned int> &list, std::map<unsigned int, std::pair<int, std::shared_ptr<IPC>>>::iterator const &it)
{
    std::string tmp = cmd;

    cmd = communication(std::to_string(this->_idCommand) + " " + cmd, it->second.second);
    if (tmp == cmd || tmp + ";" == cmd);
    else
        list.push_back(it->first);
    if (cmd.compare("Unknown pizza") == 0)
        return false;
    return true;
}

void Reception::sendCommand(std::string const &command)
{
    std::vector<unsigned int> kitchenList;
    std::string new_cmd = command;
    int status;

    if (!Parser::Contain(new_cmd, "((\\s?)+([A-Za-z]+)(\\s)+(S|M|L|XL|XXL)(\\s)+x([0-9]+)(;?))+"))
        throw std::invalid_argument("Error in command line, see help");
    for (auto it = this->_kitchens.begin(); !new_cmd.empty();) {
        if (it == this->_kitchens.end()) {
            this->initKitchen();
            ++it;
            continue;
        }
        if (waitpid(it->second.first, &status, WNOHANG) == 0) {
            if (kitchenTookCommand(new_cmd, kitchenList, it) == false)
                return;
        } else {
            it = this->_kitchens.erase(it);
            continue;
        }
        ++it;
    }
    this->_commands.insert({this->_idCommand, kitchenList});
    this->_idCommand++;
}

void Reception::checkKitchenDeath()
{
    int status;

    for (auto it = this->_kitchens.begin(); it != this->_kitchens.end();) {
        if (waitpid(it->second.first, &status, WNOHANG) != 0) {
            it = this->_kitchens.erase(it);
            continue;
        }
        ++it;
    }
}

static std::string const commandState(unsigned const int &cmdId, std::pair<int, std::shared_ptr<IPC>> &tmp)
{
    std::string state;
    int status;

    if (waitpid(tmp.first, &status, WNOHANG) == 0) {
        tmp.second << "state " + std::to_string(cmdId);
        tmp.second >> state;
    }
    return state;
}

void Reception::checkOrders()
{
    std::pair<int, std::shared_ptr<IPC>> tmp;

    for (auto it = this->_commands.begin(); it != this->_commands.end();) {
        for (auto kit = it->second.begin(); kit != it->second.end();) {
            if (commandState(it->first, this->_kitchens.find(*kit)->second).compare("yes") == 0) {
                kit = it->second.erase(kit);
                continue;
            }
            ++kit;
        }
        if (it->second.size() == 0) {
            std::cout << "Command " << it->first << " finished\n";
            PromptDisplay::printPrompt();
            it = this->_commands.erase(it);
            continue;
        }
        ++it;
    }
}
