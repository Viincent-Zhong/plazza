/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Prompt
*/

#ifndef PROMPT_HPP_
#define PROMPT_HPP_

#include "Reception.hpp"

class Prompt {
    public:
        Prompt();
        ~Prompt();
        void run(ParseParams const &params);

    private:
        Reception _reception;
};

#endif /* !PROMPT_HPP_ */
