/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** IPC
*/

#ifndef IPC_HPP_
#define IPC_HPP_

#include <sys/ipc.h>
#include <sys/msg.h>
#include <string>
#include <memory>

class IPC {
    public:
        IPC();
        IPC(std::string const &filename);
        ~IPC();
        IPC(const IPC &copy);
        IPC &operator=(const IPC &copy);
        void sendMessage(std::string const &message);
        std::string receiveMessage();
        void destroyFifo() const;
    private:
        std::string _path;
};

void operator<<(std::shared_ptr<IPC> &ipc, std::string const &str);
void operator>>(std::shared_ptr<IPC> &ipc, std::string &str);

#endif /* !IPC_HPP_ */
