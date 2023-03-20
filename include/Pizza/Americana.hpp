/*
** EPITECH PROJECT, 2022
** Project Plazza
** File description:
** Americana.hpp
*/

#ifndef AMERICANA_HPP_
#define AMERICANA_HPP_

#include "IPizzas.hpp"

class Americana : public Pizza::IPizzas {
    public:
        Americana();
        ~Americana();
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

#endif /* !AMERICANA_HPP_ */
