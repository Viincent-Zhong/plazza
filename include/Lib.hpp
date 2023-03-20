/*
** EPITECH PROJECT, 2022
** Project plazza
** File description:
** Lib.hpp
*/

#ifndef LIB_HPP_
#define LIB_HPP_

#include <string>
#include <vector>

#define PATH_FILE   "/tmp/"

class Lib {
    public:
        Lib();
        ~Lib();
        std::string getDataFile(std::string const &file);
        bool writeToFile(std::string const &path, std::string const &data);
        void splitString(std::string str, std::vector<std::string> &list, char const &c);
        bool goodChar(std::string const &str);
        bool isNumber(std::string const &str);

    protected:
    private:
};

#endif /* !LIB_HPP_ */
