//
// Created by paulnykiel on 04.05.19.
//

#ifndef SOPRAMESSAGES_SENDCHAT_H
#define SOPRAMESSAGES_SENDCHAT_H

#include <string>
#include "json.hpp"

namespace commmunication::messages::mods::broadcast {
    class SendChat {
    public:
        SendChat(const std::string &information);

        std::string getInformation() const;

        bool operator==(const SendChat &rhs) const;

        bool operator!=(const SendChat &rhs) const;

        static auto getName() -> std::string;
    private:
        std::string information;
    };
}

#endif //SOPRAMESSAGES_SENDCHAT_H
