/*
** EPITECH PROJECT, 2022
** Project Plazza
** File description:
** Regina.cpp
*/

#include "Kitchen.hpp"
#include "Pizza/Regina.hpp"

Regina::Regina()
{
    this->_name = "Regina";
    this->_timeCook = 2;
    this->_ingredient.chief_love = 0;
    this->_ingredient.doe = 1;
    this->_ingredient.eggplant = 0;
    this->_ingredient.goat_cheese = 0;
    this->_ingredient.gruyere = 1;
    this->_ingredient.ham = 1;
    this->_ingredient.mushrooms = 1;
    this->_ingredient.steak = 0;
    this->_ingredient.tomato = 1;
}

Regina::~Regina()
{
}

std::string Regina::getName()
{
    return this->_name;
}

Pizza::Ingredient const &Regina::getIngredient()
{
    return this->_ingredient;
}

unsigned int Regina::getTimeCook()
{
    return this->_timeCook;
}

void Regina::multiplyIngredient(int const &multiplier)
{
    this->_ingredient.chief_love *= multiplier;
    this->_ingredient.doe *= multiplier;
    this->_ingredient.eggplant *= multiplier;
    this->_ingredient.goat_cheese *= multiplier;
    this->_ingredient.gruyere *= multiplier;
    this->_ingredient.ham *= multiplier;
    this->_ingredient.mushrooms *= multiplier;
    this->_ingredient.steak *= multiplier;
    this->_ingredient.tomato *= multiplier;
}

void Regina::multiplyTime(int const &multiplier)
{
    this->_timeCook *= multiplier;
}
