//
// Created by paulnykiel on 21.05.19.
//

#ifndef SOPRAMESSAGES_RECONNECTCHAR_H
#define SOPRAMESSAGES_RECONNECTCHAR_H


#include <string>
#include "json.hpp"

namespace communication::messages::mods::unicast {
    class ReconnectChat {
    public:
        ReconnectChat() = default;
        explicit ReconnectChat(std::vector<std::pair<std::string, std::string>> lastTenChat);

        std::vector<std::pair<std::string, std::string>> getLastTenChat() const;

        static auto getName() -> std::string;

        bool operator==(const ReconnectChat &rhs) const;

        bool operator!=(const ReconnectChat &rhs) const;

    private:
        std::vector<std::pair<std::string, std::string>> lastTenChat;
    };

    void to_json(nlohmann::json &j, const ReconnectChat &reconnectChat);
    void from_json(const nlohmann::json &j, ReconnectChat &reconnectChat);
}

#endif //SOPRAMESSAGES_RECONNECTCHAR_H
