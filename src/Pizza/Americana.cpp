/*
** EPITECH PROJECT, 2022
** Project Plazza
** File description:
** Americana.cpp
*/

#include "Kitchen.hpp"
#include "Pizza/Americana.hpp"

Americana::Americana()
{
    this->_name = "Americana";
    this->_timeCook = 2;
    this->_ingredient.chief_love = 0;
    this->_ingredient.doe = 1;
    this->_ingredient.eggplant = 0;
    this->_ingredient.goat_cheese = 0;
    this->_ingredient.gruyere = 1;
    this->_ingredient.ham = 0;
    this->_ingredient.mushrooms = 0;
    this->_ingredient.steak = 1;
    this->_ingredient.tomato = 1;
}

Americana::~Americana()
{
}

std::string Americana::getName()
{
    return this->_name;
}

Pizza::Ingredient const &Americana::getIngredient()
{
    return this->_ingredient;
}

unsigned int Americana::getTimeCook()
{
    return this->_timeCook;
}

void Americana::multiplyIngredient(int const &multiplier)
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

void Americana::multiplyTime(int const &multiplier)
{
    this->_timeCook *= multiplier;
}
