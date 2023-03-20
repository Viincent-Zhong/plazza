/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Cook
*/

#include "Cook.hpp"
#include <iostream>

Cook::Cook()
{
    this->_status = true;
    this->_listPizza = {-1, -1};
}

Cook::~Cook()
{
}

static void WaitTime(std::promise<bool> && p, int time)
{
    auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_time = std::chrono::steady_clock::duration::zero();

    while (elapsed_time.count() < time) {
        end = std::chrono::steady_clock::now();
        elapsed_time = end - start;
    }
}

void Cook::MakePizza(int pizza)
{
    this->_status = true;
    this->_future = this->promise.get_future();
    this->_thread = std::move(std::thread(WaitTime, std::move(this->promise), pizza));
}

void Cook::waitPizza()
{
    this->_thread.join();
}

bool Cook::isWorking()
{
    if (this->_future.valid())
        this->_status = this->_future.get();
    return this->_status;
};

bool Cook::addPizza(unsigned int const &time)
{
    if (this->_listPizza.first != -1 && this->_listPizza.second != -1)
        return false;
    if (this->_listPizza.first == -1)
        this->_listPizza.first = time;
    else
        this->_listPizza.second = time;
    return true;
}

std::pair<int, int> Cook::getTimePizzas() const
{
    return this->_listPizza;
}
