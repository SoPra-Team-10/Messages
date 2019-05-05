//
// Created by paulnykiel on 04.05.19.
//

#include "SendChat.h"

namespace commmunication::messages::mods::broadcast {

    auto SendChat::getName() -> std::string {
        return "sendChat";
    }

    SendChat::SendChat(const std::string &information) : information(information) {}

    std::string SendChat::getInformation() const {
        return information;
    }

    bool SendChat::operator==(const SendChat &rhs) const {
        return information == rhs.information;
    }

    bool SendChat::operator!=(const SendChat &rhs) const {
        return !(rhs == *this);
    }
}
