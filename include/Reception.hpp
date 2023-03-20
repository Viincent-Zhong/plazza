/*
** EPITECH PROJECT, 2022
** Project plazza
** File description:
** Reception.hpp
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_

#include <map>
#include "dataStructure.hpp"
#include "ParseParams.hpp"
#include "Lib.hpp"
#include "IPC.hpp"
#include "Kitchen.hpp"
#include "Display.hpp"

class Reception {
    public:
        Reception();
        ~Reception();
        void init(ParseParams const &params);
        void prompt(ParseParams const &params);
        void getStatus(std::string const &str);
        void sendCommand(std::string const &command);
        void initKitchen();
        void checkKitchenDeath();
        bool kitchenCommandResponse(std::map<unsigned int, std::pair<int, std::shared_ptr<IPC>>>::iterator &it, std::vector<unsigned int> &commands, std::string const &command, std::string const &tmp);
        bool kitchenTookCommand(std::string &cmd, std::vector<unsigned int> &list, std::map<unsigned int, std::pair<int, std::shared_ptr<IPC>>>::iterator const &it);
        void checkOrders();

    private:
        ParseParams _params;
        std::vector<int> _listPidKitchen;
        std::map<unsigned int, std::pair<int, std::shared_ptr<IPC>>> _kitchens;
        Lib _lib;
        std::vector<command_t> _listCommand;
        Display _display;

        unsigned int _idCommand;
        unsigned int _idKitchen;
        std::map<unsigned int, std::vector<unsigned int>> _commands;
};

#endif /* !RECEPTION_HPP_ */
