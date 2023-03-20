/*
** EPITECH PROJECT, 2022
** Project plazza
** File description:
** unit_test_lib.cpp
*/

#include <criterion/criterion.h>
#include "Lib.hpp"

Test(splitString, split_simple_string)
{
    Lib lib;
    std::string str = "Hello world";
    std::string str1 = "Hello";
    std::string str2 = "world";
    std::vector<std::string> list;
    const char c = ' ';

    lib.splitString(str, list, c);
    cr_assert_eq(list.size(), 2);
    cr_assert_str_eq(list.begin()->c_str(), str1.c_str());
    cr_assert_str_eq(list.at(1).c_str(), str2.c_str());
}

Test(splitString, split_simple_string_no_spaces)
{
    Lib lib;
    std::string str = "Hello world";
    std::string str1 = "Hello ";
    std::string str2 = "orld";
    std::vector<std::string> list;
    const char c = 'w';

    lib.splitString(str, list, c);
    cr_assert_eq(list.size(), 2);
    cr_assert_str_eq(list.begin()->c_str(), str1.c_str());
    cr_assert_str_eq(list.at(1).c_str(), str2.c_str());
}

Test(splitString, split_simple_string_more_split)
{
    Lib lib;
    std::string str = "Heallao waorld";
    std::vector<std::string> list;
    const char c = 'a';

    lib.splitString(str, list, c);
    cr_assert_eq(list.size(), 4);
}

Test(isNumber, string_is_number)
{
    Lib lib;
    std::string str = "42";
    const bool result = lib.isNumber(str);

    cr_assert_eq(result, true);
}

Test(isNumber, string_is_not_number)
{
    Lib lib;
    std::string str = "-4°";
    const bool result = lib.isNumber(str);

    cr_assert_eq(result, false);
}

Test(isNumber, string_is_negative_number)
{
    Lib lib;
    std::string str = "-42";
    const bool result = lib.isNumber(str);

    cr_assert_eq(result, false);
}

Test(isNumber, string_is_empty)
{
    Lib lib;
    std::string str = "";
    const bool result = lib.isNumber(str);

    cr_assert_eq(result, false);
}

Test(goodChar, string_is_good)
{
    Lib lib;
    const std::string str = "Regina";
    const bool result = lib.goodChar(str);

    cr_assert_eq(result, true);
}

Test(goodChar, string_is_not_good)
{
    Lib lib;
    const std::string str = "Regina=pad.";
    const bool result = lib.goodChar(str);

    cr_assert_eq(result, false);
}

Test(getDataFile, string_is_not_good)
{
    Lib lib;
    const std::string str = "eheheheeheheheeheh";
    std::string result = lib.getDataFile(str);

    cr_assert_eq(result.size(), 0);
}

Test(writeToFile, write_to_file)
{
    Lib lib;
    const std::string str = "test00";
    std::string content = "Hello world";
    bool result = lib.writeToFile(str, content);
    std::string file = lib.getDataFile(str);

    cr_assert_str_eq(file.c_str(), content.c_str());
    std::remove(str.c_str());
}
