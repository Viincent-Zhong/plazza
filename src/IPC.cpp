/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** IPC
*/

#include "IPC.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdexcept>
#include <unistd.h>
#include <errno.h>

IPC::IPC()
{
}

IPC::IPC(std::string const &filename)
{
    errno = 0;

    unlink(filename.c_str());
    if (mkfifo(filename.c_str(), 0666) == -1) {
        if (errno != EEXIST)
            throw std::domain_error("Named pipe failed");
    }
    this->_path = filename;
}

IPC::~IPC()
{
}

IPC::IPC(const IPC &copy)
{
    this->_path = copy._path;
}

IPC &IPC::operator=(const IPC &copy)
{
    this->_path = copy._path;
    return *this;
}

static std::string bufferToString(char buffer[], int len)
{
    std::string message (buffer, len);

    return message;
}

void IPC::sendMessage(std::string const &message)
{
    int fd = open(this->_path.c_str(), O_WRONLY);

    write(fd, message.c_str(), message.size());
    close(fd);
}

std::string IPC::receiveMessage()
{
    char buffer[2048] = {0};
    int fd = open(this->_path.c_str(), O_RDONLY);
    int i = 0;

    for (; i < 2048 && read(fd, buffer + i, 1) > 0; ++i);
    buffer[i] = '\0';
    close(fd);
    return std::string(buffer);
}

void IPC::destroyFifo() const
{
    unlink(this->_path.c_str());
}

void operator<<(std::shared_ptr<IPC> &ipc, std::string const &str)
{
    ipc.get()->sendMessage(str);
}

void operator>>(std::shared_ptr<IPC> &ipc, std::string &str)
{
    str = ipc.get()->receiveMessage();
}
