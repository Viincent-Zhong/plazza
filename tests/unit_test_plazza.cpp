/*
** EPITECH PROJECT, 2022
** Project plazza
** File description:
** unit_test_plazza.cpp
*/

#include <criterion/criterion.h>
#include "Plazza.hpp"

Test(run, bad_params_one)
{
    int ac = 18;
    Plazza plazza;
    const bool result = plazza.run(ac, NULL);

    cr_assert_eq(result, false);
}