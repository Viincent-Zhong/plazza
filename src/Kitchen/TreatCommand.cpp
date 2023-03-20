/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** TreatCommand
*/

#include <cstring>
#include <algorithm>
#include <iostream>
#include "Pizza/Regina.hpp"
#include "Pizza/Margarita.hpp"
#include "Pizza/Americana.hpp"
#include "Pizza/Fantasia.hpp"
#include "Kitchen.hpp"

Pizza::PizzaType const isPizza(std::string const &pizza, std::map<Pizza::PizzaType, std::unique_ptr<Pizza::IPizzas>> const &pizzaList)
{
    for (auto it = pizzaList.begin(), end = pizzaList.end(); it != end; ++it) {
        if (strcasecmp(it->second.get()->getName().c_str(), pizza.c_str()) == 0)
            return it->first;
    }
    return Pizza::Error;
}

void Kitchen::giveCommandToCooks(std::vector<std::pair<unsigned int, std::shared_ptr<Pizza::IPizzas>>> const &pizzas)
{
    this->_listCommand.insert(this->_listCommand.end(), pizzas.begin(), pizzas.end());
    this->AllowCooksToTakePizza(pizzas.size());
}

std::string const Kitchen::parsePizza(std::string &cmd)
{
    std::regex regex("\\s?+([0-9]+)?\\s?+(([A-Za-z]+)\\s+(S|M|L|XL|XXL)\\s+x([0-9]+)\\s?+;?)");
    std::smatch m;
    std::vector<std::pair<unsigned int, std::shared_ptr<Pizza::IPizzas>>> new_pizzas;
    std::string tmp = cmd;
    Pizza::PizzaType pizza_type;
    unsigned int id;

    std::regex_search(tmp, m, regex);
    if ((pizza_type = isPizza(m[3], this->_listPizza)) == Pizza::Error)
        return "Unknown pizza";
    id = std::atoi(m[1].str().c_str());
    cmd = m[2];
    if (constructCommand(new_pizzas, id, pizza_type, m, cmd) == false) {
        this->giveCommandToCooks(new_pizzas);
        return cmd + m.suffix().str();
    }
    for (std::string parse = m.suffix().str(); std::regex_search(parse, m, regex); parse = m.suffix().str()) {
        if ((pizza_type = isPizza(m[3], this->_listPizza)) == Pizza::Error)
            return "Unknown pizza";
        if (constructCommand(new_pizzas, id, pizza_type, m, tmp) == false) {
            this->giveCommandToCooks(new_pizzas);
            return cmd + tmp + parse;
        }
    }
    this->giveCommandToCooks(new_pizzas);
    return "";
}

std::string const Kitchen::displayFood()
{
    std::string ingredient =
    "Goat_cheese " + std::to_string(this->food.goat_cheese) + ", " +
    "Gruyere "  + std::to_string(this->food.gruyere) + ", " +
    "Mushrooms "  + std::to_string(this->food.mushrooms) + ", " +
    "Eggplant "  + std::to_string(this->food.eggplant) + ", " +
    "Steak "  + std::to_string(this->food.steak) + ", " +
    "Ham "  + std::to_string(this->food.ham) + ", " +
    "Tomato "  + std::to_string(this->food.tomato) + ", " +
    "Doe "  + std::to_string(this->food.doe) + ", " +
    "Chief love " + std::to_string(this->food.chief_love) + "\n";
    return ingredient;
}

std::string const Kitchen::getStatus()
{
    std::string status;

    for (unsigned int i = 0; i < this->_nbCooks; ++i) {
        if (this->_occupied.find(i) == this->_occupied.end())
            status += "Cook " + std::to_string(i) + " is free\n";
        else
            status += "Cook " + std::to_string(i) + " is occupied\n";
    }
    status += displayFood() + "\n";
    return status;
}

std::string const Kitchen::parseCommand(std::string &cmd)
{
    std::string response;

    if (cmd.compare("status") == 0) {
        return this->getStatus();
    } else if ((response = sendKitchenState(cmd)).size() != 0) {
        return response;
    } else {
        return this->parsePizza(cmd);
    }
}

std::string const Kitchen::sendKitchenState(std::string &cmd)
{
    std::regex regex("state\\s+([0-9]+)");
    std::smatch m;
    unsigned int id;

    if (std::regex_search(cmd, m, regex)) {
        id = std::atoi(m[1].str().c_str());
        for (auto it = this->_listCommand.begin(); it != this->_listCommand.end(); ++it)
            if (id == it->first)
                return "no";
        for (auto it = this->_occupied.begin(); it != this->_occupied.end(); ++it)
            if (id == it->second)
                return "no";
        return "yes";
    }
    return "";
}

bool Kitchen::constructCommand(std::vector<std::pair<unsigned int, std::shared_ptr<Pizza::IPizzas>>> &pizzas, unsigned int const &id, Pizza::PizzaType const &pizza_type, std::smatch &m, std::string &line)
{
    int nbr = std::atoi(m[5].str().c_str());
    int old_nbr = nbr;

    while (nbr > 0) {
        if (this->packPizzaIntoCommand(pizzas, id, pizza_type, m) == false) {
            line = m[3].str() + " " + m[4].str() + " x" + std::to_string(nbr) + ";";
            return false;
        }
        --nbr;
    }
    return true;
}

bool Kitchen::packPizzaIntoCommand(std::vector<std::pair<unsigned int, std::shared_ptr<Pizza::IPizzas>>> &pizzas, unsigned int const &id,Pizza::PizzaType const &pizza_type, std::smatch &m)
{
    std::shared_ptr<Pizza::IPizzas> pizza;

    if (this->_listCommand.size() + pizzas.size() + 1 > this->_availableCooks)
        return false;
    switch (pizza_type)
    {
        case Pizza::Regina:
            pizza = std::make_shared<Regina>(Regina());
            break;
        case Pizza::Americana:
            pizza = std::make_shared<Americana>(Americana());
            break;
        case Pizza::Fantasia:
            pizza = std::make_shared<Fantasia>(Fantasia());
            break;
        case Pizza::Margarita:
            pizza = std::make_shared<Margarita>(Margarita());
            break;
    }
    pizza.get()->multiplyTime(this->_pizzaSize.find(m[4])->second + this->_cookingTime);
    pizzas.push_back({id, pizza});
    return true;
}
