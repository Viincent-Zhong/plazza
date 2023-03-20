/*
** EPITECH PROJECT, 2022
** Project plazza
** File description:
** Display.hpp
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include <map>
#include "dataStructure.hpp"
#include "Lib.hpp"

namespace PromptDisplay {
    void printPrompt();
};

class Display {
    public:
        Display();
        ~Display();
        void printStatusCommand(std::vector<command_t> const &listCommand);
        void getDataIngredient(status_t &status, std::string const &data, Lib lib);
        void getDataCooks(status_t &status, std::string const &data, Lib lib);
        void getDataStatus(std::string const &data);
        void printIngredient(Pizza::Ingredient const &ingredient);
        void printCooks(std::vector<cook_t> const &data);
        void printStatus(status_t const &status);
        void displayStatus(std::string const &data, std::vector<command_t> const &listCommand);

    protected:
    private:
        std::map<unsigned int, std::unique_ptr<Pizza::IPizzas>> _listPizza;
        Lib _lib;
};

#endif /* !DISPLAY_HPP_ */
