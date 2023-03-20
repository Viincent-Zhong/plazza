/*
** EPITECH PROJECT, 2022
** Project Plazza
** File description:
** IPizzas.hpp
*/

#ifndef IPIZZAS_HPP_
#define IPIZZAS_HPP_

#include <string>

/**
 * @brief namespace for pizzas in Plazza
 * @author Pierre-Alexandre
 * @version 1.0.0
 * @date 04.05.2022
 * 
 */
namespace Pizza {
    struct Ingredient
    {
        unsigned int doe;
        unsigned int tomato;
        unsigned int ham;
        unsigned int steak;
        unsigned int eggplant;
        unsigned int mushrooms;
        unsigned int gruyere;
        unsigned int goat_cheese;
        unsigned int chief_love;
    };

    enum PizzaType
    {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8,
        Error = -1
    };

    enum PizzaSize
    {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };

    /**
     * @brief Iterface for each Pizza in Plazza
     * 
     */
    class IPizzas {
        public:
            /**
             * @brief Destroy the IPizzas object
             * 
             */
            virtual ~IPizzas() = default;
            /**
             * @brief Get the Name of pizza
             * 
             * @return std::string 
             */
            virtual std::string getName() = 0;
            /**
             * @brief Get the Ingredient object
             * 
             * @param ingredient struct of all ingredient in the kitchen's fridge
             * @return true can create pizza and remove ingredient in the struct
             * @return false cannot create pizza, remove no element in the struct
             */
            virtual Ingredient const &getIngredient() = 0;
            /**
             * @brief Get the Time Cook of pizza
             * 
             * @return unsigned int the time in second
             */
            virtual unsigned int getTimeCook() = 0;
            virtual void multiplyIngredient(int const &multiplier) = 0;
            virtual void multiplyTime(int const &multiplier) = 0;
    };
}

#endif /* !IPIZZAS_HPP_ */
