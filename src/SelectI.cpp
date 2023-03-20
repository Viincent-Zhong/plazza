/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** SelectI
*/

#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <string.h>
#include "SelectI.hpp"

SelectI::SelectI(int fd, int sec)
{
    this->_fd = fd;
    this->_tv.tv_sec = sec;
    this->_tv.tv_usec = 0;
}

SelectI::~SelectI()
{
}

int SelectI::Select()
{
    FD_ZERO(&this->_rdfs);
    FD_SET(this->_fd, &this->_rdfs);
    memcpy(&this->_tmp, &this->_tv, sizeof(this->_tv));
    return select(this->_fd + 1, &this->_rdfs, NULL, NULL, &this->_tmp);
}

int SelectI::IsSet()
{
    return FD_ISSET(this->_fd, &this->_rdfs);
}

