//
// Created by paulnykiel on 21.05.19.
//

#include "ReconnectChat.h"

#include <utility>

namespace communication::messages::mods::unicast {
    ReconnectChat::ReconnectChat(
            std::vector<std::pair<std::string, std::string>> lastTenChat) : lastTenChat(std::move(lastTenChat)) {}

    std::vector<std::pair<std::string, std::string>>
    ReconnectChat::getLastTenChat() const {
        return lastTenChat;
    }

    auto ReconnectChat::getName() -> std::string {
        return "reconnectChat";
    }

    bool ReconnectChat::operator==(const ReconnectChat &rhs) const {
        return lastTenChat == rhs.lastTenChat;
    }

    bool ReconnectChat::operator!=(const ReconnectChat &rhs) const {
        return !(rhs == *this);
    }

    void to_json(nlohmann::json &j, const ReconnectChat &reconnectChat) {
        j["lastTenChat"] = nlohmann::json::array();
        for (const auto &msg : reconnectChat.getLastTenChat()) {
            nlohmann::json item{{"senderUserName", msg.first}, {"information", msg.second}};
            j["lastTenChat"].push_back(item);
        }
    }

    void from_json(const nlohmann::json &j, ReconnectChat &reconnectChat) {
        std::vector<std::pair<std::string,std::string>> messages;
        for (const auto &msg : j.at("lastTenChat")) {
            messages.emplace_back(msg.at("senderUserName").get<std::string>(),
                    msg.at("information").get<std::string>());
        }
        reconnectChat = ReconnectChat{messages};
    }
}
