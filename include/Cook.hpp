/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Cook
*/

#ifndef COOK_HPP_
#define COOK_HPP_

#include <thread>
#include <future>
#include "Pizza/IPizzas.hpp"

class Cook {
    public:
        Cook();
        ~Cook();
        Cook(const Cook&) = delete;
        Cook(Cook&&) = default;
        // MakePizza (Pizza, Parametre de la cuisine)
        void MakePizza(int pizza);
        void waitPizza();
        bool isWorking();
        bool addPizza(unsigned int const &time);
        std::pair<int, int> getTimePizzas() const;

    private:
        std::promise<bool> promise;
        std::thread _thread;
        std::future<bool> _future;
        std::pair<int, int> _listPizza;
        bool _status;
};

#endif /* !COOK_HPP_ */
