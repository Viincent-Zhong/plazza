/*
** EPITECH PROJECT, 2022
** Project plazza
** File description:
** ParseParams.hpp
*/

#ifndef PARSEPARAMS_HPP_
#define PARSEPARAMS_HPP_

#define NB_ARG  3

class ParseParams {
    public:
        ParseParams();
        ~ParseParams();
        void getParams(int ac, char **av);
        unsigned int getCookingTime() const;
        unsigned int getNbCooks() const;
        unsigned int getTimeIngredient() const;

    protected:
    private:
        unsigned int _mulCookingTime;
        unsigned int _nbCooks;
        unsigned int _timeReplaceIngredient;
};

#endif /* !PARSEPARAMS_HPP_ */
