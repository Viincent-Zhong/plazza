/*
** EPITECH PROJECT, 2022
** Project plazza
** File description:
** unit_test_parse_params.cpp
*/

#include <criterion/criterion.h>
#include "ParseParams.hpp"

Test(getParams, good_params)
{
    int ac = 3;
    char *av[] = {"2", "5", "2000", NULL};
    ParseParams params;

    params.getParams(ac, av);
    cr_assert_eq(params.getCookingTime(), 2);
    cr_assert_eq(params.getNbCooks(), 5);
    cr_assert_eq(params.getTimeIngredient(), 2000);
}

Test(getParams, wrong_number_of_params)
{
    int ac = 10;
    ParseParams params;
    bool result = true;

    try {
        params.getParams(ac, NULL);
    } catch(std::invalid_argument &e) {
        result = false;
    }
    cr_assert_eq(result, false);
}

Test(getParams, bad_params_one)
{
    int ac = 3;
    char *av[] = {"2", "-5", "2000", NULL};
    ParseParams params;
    bool result = true;

    try {
        params.getParams(ac, av);
    } catch(std::invalid_argument &e) {
        result = false;
    }
    cr_assert_eq(result, false);
}
