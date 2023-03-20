/*
** EPITECH PROJECT, 2022
** Project plazza
** File description:
** dataStructure.hpp
*/

#ifndef DATASTRUCTURE_HPP_
#define DATASTRUCTURE_HPP_

#include <vector>
#include "Pizza/IPizzas.hpp"

typedef struct cook_s {
    unsigned int id;
    unsigned int pizza_one;
    unsigned int pizza_two;
    unsigned int time;
} cook_t;

typedef struct status_s {
    std::vector<cook_t> cooks;
    Pizza::Ingredient ingredient;
} status_t;

typedef struct command_s {
    unsigned int id;
    std::vector<int> pizza;
    // pizza faite / pizza max
    std::vector<std::pair<int, int>> status;
} command_t;

#endif /* !DATASTRUCTURE_HPP_ */
