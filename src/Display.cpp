/*
** EPITECH PROJECT, 2022
** Project plazza
** File description:
** Display.cpp
*/

#include <iostream>
#include <memory>
#include "Display.hpp"
#include "Pizza/Regina.hpp"
#include "Pizza/Margarita.hpp"
#include "Pizza/Americana.hpp"
#include "Pizza/Fantasia.hpp"

Display::Display()
{
    this->_listPizza.insert({Pizza::Regina, std::make_unique<Regina>(Regina())});
    this->_listPizza.insert({Pizza::Margarita, std::make_unique<Margarita>(Margarita())});
    this->_listPizza.insert({Pizza::Americana, std::make_unique<Americana>(Americana())});
    this->_listPizza.insert({Pizza::Fantasia, std::make_unique<Fantasia>(Fantasia())});
}

Display::~Display()
{
}

void Display::printStatusCommand(std::vector<command_t> const &listCommand)
{
    std::cout << "Commands:\n";
    for (auto command : listCommand) {
        std::cout << "Command " << command.id << "\n";
        for (int i = 0; i != command.pizza.size(); ++i) {
            std::cout << command.pizza.at(i) << ": ";
            std::cout << command.status.at(i).first << "/" << command.status.at(i).second << "\n";
        }
    }
}

void Display::getDataIngredient(status_t &status, std::string const &data, Lib lib)
{
    std::vector<std::string> dataIngredient;

    lib.splitString(data, dataIngredient, ',');
    status.ingredient.chief_love = std::stoi(dataIngredient.at(0));
    status.ingredient.doe = std::stoi(dataIngredient.at(1));
    status.ingredient.eggplant = std::stoi(dataIngredient.at(2));
    status.ingredient.goat_cheese = std::stoi(dataIngredient.at(3));
    status.ingredient.gruyere = std::stoi(dataIngredient.at(4));
    status.ingredient.ham = std::stoi(dataIngredient.at(5));
    status.ingredient.mushrooms = std::stoi(dataIngredient.at(6));
    status.ingredient.steak = std::stoi(dataIngredient.at(7));
    status.ingredient.tomato = std::stoi(dataIngredient.at(8));
}

void Display::getDataCooks(status_t &status, std::string const &data, Lib lib)
{
    cook_t etchebest;
    std::vector<std::string> cooks;
    std::vector<std::string> dataCooks;

    lib.splitString(data, cooks, ';');
    for (int i = 0; i != cooks.size(); ++i) {
        lib.splitString(cooks.at(i), dataCooks, ',');
        etchebest.id = std::stoi(dataCooks.at(0));
        etchebest.pizza_one = std::stoi(dataCooks.at(1));
        etchebest.pizza_two = std::stoi(dataCooks.at(2));
        status.cooks.push_back(etchebest);
        dataCooks.clear();
    }
}

void Display::getDataStatus(std::string const &data)
{
    status_t status;
    std::vector<std::string> splitdata;

    this->_lib.splitString(data, splitdata, '/');
    getDataCooks(status, splitdata.at(0), this->_lib);
    getDataIngredient(status, splitdata.at(1), this->_lib);
    this->printStatus(status);
}

void Display::printIngredient(Pizza::Ingredient const &ingredient)
{
    std::cout << "\nchief love: " << ingredient.chief_love << "\n";
    std::cout << "goat cheese: " << ingredient.goat_cheese << "\n";
    std::cout << "gruyere: " << ingredient.gruyere << "\n";
    std::cout << "mushrooms: " << ingredient.mushrooms << "\n";
    std::cout << "eggplant: " << ingredient.eggplant << "\n";
    std::cout << "steak: " << ingredient.steak << "\n";
    std::cout << "ham: " << ingredient.ham << "\n";
    std::cout << "tomato: " << ingredient.tomato << "\n";
    std::cout << "doe: " << ingredient.doe << "\n";
}

void Display::printCooks(std::vector<cook_t> const &data)
{
    for (auto const &cooks : data) {
        std::cout << "Cooks " << cooks.id << ": ";
        if (cooks.pizza_one == 0) {
            std::cout << "waiting\n";
        } else {
            std::cout << "pizza " << this->_listPizza.find(cooks.pizza_one)->second->getName() << " | ";
            if (cooks.pizza_two == 0)
                std::cout << "waiting\n";
            else
                std::cout << "pizza " << this->_listPizza.find(cooks.pizza_two)->second->getName() << "\n";
        }
    }
}

void Display::printStatus(status_t const &status)
{
    printCooks(status.cooks);
    printIngredient(status.ingredient);
}

void Display::displayStatus(std::string const &data, std::vector<command_t> const &listCommand)
{
    std::cout << data;
}

void PromptDisplay::printPrompt()
{
    time_t currentTime;
    struct tm *localTime;
    time( &currentTime );
    currentTime += 1*30*60;
    localTime= localtime(&currentTime);
    int Hour = localTime->tm_hour;
    int Min = localTime->tm_min - 30;
    int Sec = localTime->tm_sec;

    std::cout << "┬─[Plazza]─[" << Hour << ":" << Min << ":" << Sec << "]─[Reception]\n";
    std::cout << "╰─>$ ";
    std::cout.flush();
}