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
        static auto getName() -> std::string;

    private:
        std::string information;
    };
}

#endif //SOPRAMESSAGES_SENDCHAT_H
