/*
** EPITECH PROJECT, 2022
** Project plazza
** File description:
** Kitchen.cpp
*/

#include <iostream>
#include <unistd.h>
#include <mutex>
#include "Kitchen.hpp"
#include "Pizza/Regina.hpp"
#include "Pizza/Margarita.hpp"
#include "Pizza/Americana.hpp"
#include "Pizza/Fantasia.hpp"

Kitchen::Kitchen()
{
}

Kitchen::~Kitchen()
{
}

Kitchen::Kitchen(unsigned int const &nbCooks, unsigned int const &cookingTime, unsigned int const &timeReload, std::shared_ptr<IPC> const &ipc)
{
    this->_tookCommand = false;
    this->_stop = false;
    this->_ipc = ipc;
    this->_initiedCooks = 0;
    this->_availableCooks = nbCooks * 2;
    this->_nbCooks = nbCooks;
    this->_cookingTime = cookingTime;
    this->_timeReload = timeReload;
    this->_listPizza.insert({Pizza::Regina, std::make_unique<Regina>(Regina())});
    this->_listPizza.insert({Pizza::Margarita, std::make_unique<Margarita>(Margarita())});
    this->_listPizza.insert({Pizza::Americana, std::make_unique<Americana>(Americana())});
    this->_listPizza.insert({Pizza::Fantasia, std::make_unique<Fantasia>(Fantasia())});
}

void Kitchen::AllowCooksToTakePizza(std::size_t const &nbr)
{
    this->_tookCommand = true;
    for (int i = 0; i < nbr; ++i) {
        this->cooks_cv.notify_one();
    }
}

void Kitchen::CommandThread()
{
    std::string command;

    while (!this->_stop) {
        if (this->_parse == true) {
            this->_ipc >> command;
            this->_ipc << this->parseCommand(command);
        }
    }
}

void Kitchen::cooking(unsigned int const &id)
{
    unsigned int timeCook = 0;
    Pizza::Ingredient ingr;
    std::shared_ptr<Pizza::IPizzas> pizzaGot;
    std::pair<std::map<unsigned int, unsigned int>::iterator, bool> tmp;

    this->_initiedCooks++;
    if (this->_initiedCooks == this->_nbCooks)
        this->_parse = true;

    while (!this->_stop) {
        {
            std::unique_lock <std::mutex> lk(this->cooks_mute);
            this->cooks_cv.wait(lk);
            if (this->_stop)
                break;
            this->_availableCooks--;
            pizzaGot = this->_listCommand.begin()->second;
            tmp = this->_occupied.insert({id, this->_listCommand.begin()->first});
            this->_listCommand.erase(this->_listCommand.begin());
            ingr = pizzaGot->getIngredient();
            if (ingr > this->food)
                this->refill_food(ingr);
            this->food = this->food - ingr;
            timeCook = pizzaGot->getTimeCook();
        }
        sleep(timeCook);
        {
            std::unique_lock <std::mutex> response(this->cooks_mute);
            this->_occupied.erase(tmp.first);
            this->order_cv.notify_one();
        }
    }
}

void Kitchen::CooksPool()
{
    int state = 0;

    while (!this->_stop) {
        {
            std::unique_lock <std::mutex> uk(this->order_mute);
            this->order_cv.wait(uk);
            this->_availableCooks++;
            if (this->_listCommand.size() == 0 && this->_occupied.size() == 0) {
                this->_tookCommand = false;
                this->timer_cv.notify_one();
            } else if (this->_listCommand.size() != 0)
                this->cooks_cv.notify_one();
        }
    }
}

void Kitchen::inactivity(unsigned int const &sec)
{
    while (!this->_stop) {
        {
            std::unique_lock <std::mutex>lk(this->timer_mute);
            this->timer_cv.wait(lk);
            sleep(sec);
            if (this->_tookCommand) {
                this->_tookCommand = false;
                continue;
            }
            if (this->_listCommand.size() == 0 && this->_occupied.size() == 0) {
                this->_stop = true;
                this->_ipc->destroyFifo();
                this->cooks_cv.notify_all();
                break;
            }
        }
    }
}

void Kitchen::run()
{
    std::thread pool_thread(&Kitchen::CooksPool, this);
    std::thread command_thread(&Kitchen::CommandThread, this);
    std::thread timer_thread(&Kitchen::inactivity, this, 5);
    std::vector<std::thread> listThread;

    for (int i = 0; i != this->_nbCooks; ++i)
        listThread.push_back(std::thread(&Kitchen::cooking, this, i));

    timer_thread.join();
    for (auto &thread : listThread)
        thread.detach();
    pool_thread.detach();
    command_thread.detach();
    exit(0);
}

bool operator>=(Pizza::Ingredient const &one, Pizza::Ingredient const &two)
{
    return (one.chief_love >= two.chief_love &&
            one.doe >= two.doe &&
            one.eggplant >= two.eggplant &&
            one.goat_cheese >= two.goat_cheese &&
            one.gruyere >= two.gruyere &&
            one.ham >= two.ham &&
            one.mushrooms >= two.mushrooms &&
            one.steak >= two.steak &&
            one.tomato >= two.tomato);
}

bool operator>(Pizza::Ingredient const &one, Pizza::Ingredient const &two)
{
    return (one.chief_love > two.chief_love ||
            one.doe > two.doe ||
            one.eggplant > two.eggplant ||
            one.goat_cheese > two.goat_cheese ||
            one.gruyere > two.gruyere ||
            one.ham > two.ham ||
            one.mushrooms > two.mushrooms ||
            one.steak > two.steak ||
            one.tomato > two.tomato);
}

Pizza::Ingredient operator-(Pizza::Ingredient &one, Pizza::Ingredient const &two)
{
    one.chief_love -= two.chief_love;
    one.doe -= two.doe;
    one.eggplant -= two.eggplant;
    one.goat_cheese -= two.goat_cheese;
    one.gruyere -= two.gruyere;
    one.ham -= two.ham;
    one.mushrooms -= two.mushrooms;
    one.steak -= two.steak;
    one.tomato -= two.tomato;
    return one;
}

void Kitchen::start_time()
{
    this->_refill_timer_start = std::chrono::steady_clock::now();
}

void Kitchen::refill_food(Pizza::Ingredient const &ingredient)
{
    while (ingredient > this->food) {
        sleep(this->_timeReload / 1000);
        if (this->food.chief_love < 5)
            this->food.chief_love += 1;
        if (this->food.doe < 5)
            this->food.doe += 1;
        if (this->food.eggplant < 5)
            this->food.eggplant += 1;
        if (this->food.goat_cheese < 5)
            this->food.goat_cheese += 1;
        if (this->food.gruyere < 5)
            this->food.gruyere += 1;
        if (this->food.ham < 5)
            this->food.ham += 1;
        if (this->food.mushrooms < 5)
            this->food.mushrooms += 1;
        if (this->food.steak < 5)
            this->food.steak += 1;
        if (this->food.tomato < 5)
            this->food.tomato += 1;
    }
}
