/*
** EPITECH PROJECT, 2022
** Project Plazza
** File description:
** unit_test_kitchen.cpp
*/

#include <criterion/criterion.h>
#include "Kitchen.hpp"

Test(operator, operator_for_struct_sup)
{
    Pizza::Ingredient one = {5, 5, 5, 5, 5, 5, 5, 5, 5};
    Pizza::Ingredient two = {0, 1, 0, 0, 1, 0, 0, 1, 1};
    bool result = one >= two;

    cr_assert_eq(result, true);
}

Test(operator, operator_for_struct_inf)
{
    Pizza::Ingredient two = {5, 5, 5, 5, 5, 5, 5, 5, 5};
    Pizza::Ingredient one = {0, 1, 0, 0, 1, 0, 0, 1, 1};
    bool result = one >= two;
    
    cr_assert_eq(result, false);
}

Test(operator, operator_for_struct_eq)
{
    Pizza::Ingredient one = {5, 5, 5, 5, 5, 5, 5, 5, 5};
    Pizza::Ingredient two = {5, 5, 5, 5, 5, 5, 5, 5, 5};
    bool result = one >= two;

    cr_assert_eq(result, true);
}

Test(operator, operator_for_update_struct)
{
    Pizza::Ingredient one = {5, 5, 5, 5, 5, 5, 5, 5, 5};
    Pizza::Ingredient two = {0, 1, 0, 0, 1, 0, 0, 1, 1};

    one = one - two;
    cr_assert_eq(one.chief_love, 4);
    cr_assert_eq(one.doe, 5);
    cr_assert_eq(one.eggplant, 4);
    cr_assert_eq(one.goat_cheese, 4);
    cr_assert_eq(one.gruyere, 5);
    cr_assert_eq(one.ham, 5);
    cr_assert_eq(one.mushrooms, 5);
    cr_assert_eq(one.steak, 5);
    cr_assert_eq(one.tomato, 4);
}
