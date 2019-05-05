//
// Created by paulnykiel on 04.05.19.
//

#include "SendChat.h"

#include <utility>

namespace commmunication::messages::mods::broadcast {

    auto SendChat::getName() -> std::string {
        return "sendChat";
    }

    SendChat::SendChat(std::string information) : information(std::move(information)) {}

    std::string SendChat::getInformation() const {
        return information;
    }

    bool SendChat::operator==(const SendChat &rhs) const {
        return information == rhs.information;
    }

    bool SendChat::operator!=(const SendChat &rhs) const {
        return !(rhs == *this);
    }

    void to_json(nlohmann::json &j, const SendChat &sendChat) {
        j["information"] = sendChat.getInformation();
    }

    void from_json(const nlohmann::json &j, SendChat &sendChat) {
        sendChat = SendChat{
            j.at("information").get<std::string>()
        };
    }
}
