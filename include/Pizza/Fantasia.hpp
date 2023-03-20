/*
** EPITECH PROJECT, 2022
** Project Plazza
** File description:
** Fantasia.hpp
*/

#ifndef FANTASIA_HPP_
#define FANTASIA_HPP_

#include "IPizzas.hpp"

class Fantasia : public Pizza::IPizzas {
    public:
        Fantasia();
        ~Fantasia();
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

#endif /* !FANTASIA_HPP_ */
