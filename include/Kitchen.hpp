/*
** EPITECH PROJECT, 2022
** Project plazza
** File description:
** Kitchen.hpp
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include <fstream>
#include <utility>
#include <map>
#include <memory>
#include <chrono>
#include <regex>
#include <list>
#include "Lib.hpp"
#include "IPC.hpp"
#include "Pizza/IPizzas.hpp"
#include "Cook.hpp"

#define TIME_CLOSE  5

struct Command {
    Pizza::PizzaSize size;
    Pizza::PizzaType pizza;
    unsigned int id;
};

enum CookState {
    BAKING = 0,
    NEED_REFILL = 1
};

struct Cooks {
    int state;
};

class Kitchen {
    public:
        Kitchen();
        Kitchen(unsigned int const &nbCooks, unsigned int const &cookingTime, unsigned int const &timeReload, std::shared_ptr<IPC> const &ipc);
        ~Kitchen();
        std::string const parseCommand(std::string &cmd);
        std::string const parsePizza(std::string &cmd);
        std::string const getStatus();
        std::string const displayFood();
        void run();
        void start_time();
        void refill_food(Pizza::Ingredient const &ingredient);
        void cooking(unsigned int const &id);
        void CommandThread();
        bool packPizzaIntoCommand(std::vector<std::pair<unsigned int, std::shared_ptr<Pizza::IPizzas>>> &pizzas, unsigned int const &id,Pizza::PizzaType const &pizza_type, std::smatch &m);
        bool constructCommand(std::vector<std::pair<unsigned int, std::shared_ptr<Pizza::IPizzas>>> &pizzas, unsigned int const &id,Pizza::PizzaType const &pizza_type, std::smatch &m, std::string &line);
        void giveCommandToCooks(std::vector<std::pair<unsigned int, std::shared_ptr<Pizza::IPizzas>>> const &pizzas);
        std::string const sendKitchenState(std::string &cmd);
        void AllowCooksToTakePizza(std::size_t const &nbr);
        void CooksPool();
        void inactivity(unsigned int const &sec);

    private:
        std::map<std::string, Pizza::PizzaSize> _pizzaSize = {
            {"S", Pizza::S}, {"M", Pizza::M}, {"L", Pizza::L},
            {"XL", Pizza::XL}, {"XXL", Pizza::XXL}};
        std::map<Pizza::PizzaType, std::unique_ptr<Pizza::IPizzas>> _listPizza;
        std::shared_ptr<IPC> _ipc;
        Lib _lib;

        std::vector<std::pair<unsigned int, std::shared_ptr<Pizza::IPizzas>>> _listCommand;
        std::map<unsigned int, unsigned int> _occupied;
        Pizza::Ingredient food = {5, 5, 5, 5, 5, 5, 5, 5, 5};
        std::chrono::steady_clock::time_point _refill_timer_start;

        std::mutex timer_mute;
        std::condition_variable timer_cv;
        std::mutex order_mute;
        std::condition_variable order_cv;
        std::mutex cooks_mute;
        std::condition_variable cooks_cv;
        int _availableCooks;
        bool _tookCommand;

        int _initiedCooks;
        bool _parse;
        unsigned int _nbCooks;
        unsigned int _cookingTime;
        unsigned int _timeReload;
        bool _stop;
};

bool operator>=(Pizza::Ingredient const &one, Pizza::Ingredient const &two);
bool operator>(Pizza::Ingredient const &one, Pizza::Ingredient const &two);
Pizza::Ingredient operator-(Pizza::Ingredient &one, Pizza::Ingredient const &two);
std::ostream &operator<<(std::ostream &stream, Pizza::Ingredient const &ingr);

#endif /* !KITCHEN_HPP_ */
