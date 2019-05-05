//
// Created by paulnykiel on 04.05.19.
//

#include "GlobalChat.h"

namespace commmunication::messages::mods::broadcast {

    auto GlobalChat::getName() -> std::string {
        return "globalChat";
    }

    GlobalChat::GlobalChat(const std::string &senderUserName, const std::string &information) : senderUserName(
            senderUserName), information(information) {}

    std::string GlobalChat::getSenderUserName() const {
        return senderUserName;
    }

    std::string GlobalChat::getInformation() const {
        return information;
    }

    bool GlobalChat::operator==(const GlobalChat &rhs) const {
        return senderUserName == rhs.senderUserName &&
               information == rhs.information;
    }

    bool GlobalChat::operator!=(const GlobalChat &rhs) const {
        return !(rhs == *this);
    }

    void to_json(nlohmann::json &j, const GlobalChat &globalChat) {
        j["senderUserName"] = globalChat.getSenderUserName();
        j["information"] = globalChat.getInformation();
    }

    void from_json(const nlohmann::json &j, GlobalChat &globalChat) {
        globalChat = GlobalChat{
            j.at("senderUserName").get<std::string>(),
            j.at("information").get<std::string>()
        };
    }
}
