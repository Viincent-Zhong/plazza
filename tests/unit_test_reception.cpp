/*
** EPITECH PROJECT, 2022
** Project plazza
** File description:
** unit_test_reception.cpp
*/

#include <criterion/criterion.h>
#include "Reception.hpp"
#include "Parser.hpp"

Test(verifLine, good_line)
{
    Reception reception;
    const std::string line = "Regina XL x2";
    const bool result = Parser::Contain(line, "((\\s?)+([A-Za-z]+)(\\s)+(S|M|L|XL|XXL)(\\s)+x([0-9]+)(;?))+");

    cr_assert_eq(result, true);
}

Test(verifLine, too_small_line)
{
    Reception reception;
    const std::string line = "Regina";
    const bool result = Parser::Contain(line, "((\\s?)+([A-Za-z]+)(\\s)+(S|M|L|XL|XXL)(\\s)+x([0-9]+)(;?))+");

    cr_assert_eq(result, false);
}

Test(verifLine, too_big_line)
{
    Reception reception;
    const std::string line = "Regina XL x2 x2 x2";
    const bool result = Parser::Contain(line, "((\\s?)+([A-Za-z]+)(\\s)+(S|M|L|XL|XXL)(\\s)+x([0-9]+)(;?))+");

    cr_assert_eq(result, true);
}

Test(verifLine, bad_name)
{
    Reception reception;
    const std::string line = "Regina=. XL x2";
    const bool result = Parser::Contain(line, "((\\s?)+([A-Za-z]+)(\\s)+(S|M|L|XL|XXL)(\\s)+x([0-9]+)(;?))+");

    cr_assert_eq(result, false);
}

Test(verifLine, bad_pizza_size)
{
    Reception reception;
    const std::string line = "Regina XAL x2";
    const bool result = Parser::Contain(line, "((\\s?)+([A-Za-z]+)(\\s)+(S|M|L|XL|XXL)(\\s)+x([0-9]+)(;?))+");

    cr_assert_eq(result, false);
}

Test(verifLine, bad_quantities_one)
{
    Reception reception;
    const std::string line = "Regina XL 2";
    const bool result = Parser::Contain(line, "((\\s?)+([A-Za-z]+)(\\s)+(S|M|L|XL|XXL)(\\s)+x([0-9]+)(;?))+");

    cr_assert_eq(result, false);
}

Test(verifLine, bad_quantities_two)
{
    Reception reception;
    const std::string line = "Regina XL x";
    const bool result = Parser::Contain(line, "((\\s?)+([A-Za-z]+)(\\s)+(S|M|L|XL|XXL)(\\s)+x([0-9]+)(;?))+");

    cr_assert_eq(result, false);
}

Test(verifLine, bad_quantities_three)
{
    Reception reception;
    const std::string line = "Regina XL xA";
    const bool result = Parser::Contain(line, "((\\s?)+([A-Za-z]+)(\\s)+(S|M|L|XL|XXL)(\\s)+x([0-9]+)(;?))+");

    cr_assert_eq(result, false);
}

Test(verifLine, bad_quantities_four)
{
    Reception reception;
    const std::string line = "Regina XL a2";
    const bool result = Parser::Contain(line, "((\\s?)+([A-Za-z]+)(\\s)+(S|M|L|XL|XXL)(\\s)+x([0-9]+)(;?))+");

    cr_assert_eq(result, false);
}

Test(verifLine, bad_quantities_five)
{
    Reception reception;
    const std::string line = "Regina XL aA";
    const bool result = Parser::Contain(line, "((\\s?)+([A-Za-z]+)(\\s)+(S|M|L|XL|XXL)(\\s)+x([0-9]+)(;?))+");

    cr_assert_eq(result, false);
}
