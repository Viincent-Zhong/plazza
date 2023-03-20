/*
** EPITECH PROJECT, 2022
** Project Plazza
** File description:
** Fantasia.cpp
*/

#include "Kitchen.hpp"
#include "Pizza/Fantasia.hpp"

Fantasia::Fantasia()
{
    this->_name = "Fantasia";
    this->_timeCook = 4;
    this->_ingredient.chief_love = 1;
    this->_ingredient.doe = 1;
    this->_ingredient.eggplant = 1;
    this->_ingredient.goat_cheese = 1;
    this->_ingredient.gruyere = 0;
    this->_ingredient.ham = 0;
    this->_ingredient.mushrooms = 0;
    this->_ingredient.steak = 0;
    this->_ingredient.tomato = 1;
}

Fantasia::~Fantasia()
{
}

std::string Fantasia::getName()
{
    return this->_name;
}

Pizza::Ingredient const &Fantasia::getIngredient()
{
    return this->_ingredient;
}

unsigned int Fantasia::getTimeCook()
{
    return this->_timeCook;
}

void Fantasia::multiplyIngredient(int const &multiplier)
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

void Fantasia::multiplyTime(int const &multiplier)
{
    this->_timeCook *= multiplier;
}
