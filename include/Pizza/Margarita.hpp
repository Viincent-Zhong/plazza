/*
** EPITECH PROJECT, 2022
** Project Plazza
** File description:
** Maragrita.hpp
*/

#ifndef MARGARITA_HPP_
#define MARGARITA_HPP_

#include "IPizzas.hpp"

class Margarita : public Pizza::IPizzas {
    public:
        Margarita();
        ~Margarita();
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

#endif /* !MARGARITA_HPP_ */
