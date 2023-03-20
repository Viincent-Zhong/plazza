/*
** EPITECH PROJECT, 2022
** Project Plazza
** File description:
** Regina.hpp
*/

#ifndef REGINA_HPP_
#define REGINA_HPP_

#include "IPizzas.hpp"

class Regina : public Pizza::IPizzas {
    public:
        Regina();
        ~Regina();
        std::string getName();
        Pizza::Ingredient const &getIngredient();
        unsigned int getTimeCook();
        void multiplyIngredient(int const &multiplier);
        void multiplyTime(int const &multiplier);

    protected:
    private:
        std::string _name;
        Pizza::Ingredient _ingredient;
        unsigned int _timeCook;
};

#endif /* !REGINA_HPP_ */
