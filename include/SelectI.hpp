/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** SelectI
*/

#ifndef SELECTI_HPP_
#define SELECTI_HPP_

class SelectI {
    public:
        SelectI(int fd, int sec);
        ~SelectI();
        int Select();
        int IsSet();

    private:
        fd_set _rdfs;
        struct timeval _tv;
        struct timeval _tmp;
        int _fd;
};

#endif /* !SELECTI_HPP_ */
