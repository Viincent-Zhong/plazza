/*
** EPITECH PROJECT, 2022
** Project Plazza
** File description:
** Margarita.cpp
*/

#include "Kitchen.hpp"
#include "Pizza/Margarita.hpp"

Margarita::Margarita()
{
    this->_name = "Margarita";
    this->_timeCook = 1;
    this->_ingredient.chief_love = 0;
    this->_ingredient.doe = 1;
    this->_ingredient.eggplant = 0;
    this->_ingredient.goat_cheese = 0;
    this->_ingredient.gruyere = 1;
    this->_ingredient.ham = 0;
    this->_ingredient.mushrooms = 0;
    this->_ingredient.steak = 0;
    this->_ingredient.tomato = 1;
}

Margarita::~Margarita()
{
}

std::string Margarita::getName()
{
    return this->_name;
}

Pizza::Ingredient const &Margarita::getIngredient()
{
    return this->_ingredient;
}

unsigned int Margarita::getTimeCook()
{
    return this->_timeCook;
}

void Margarita::multiplyIngredient(int const &multiplier)
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

void Margarita::multiplyTime(int const &multiplier)
{
    this->_timeCook *= multiplier;
}
