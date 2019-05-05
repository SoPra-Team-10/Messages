//
// Created by paulnykiel on 04.05.19.
//

#ifndef SOPRAMESSAGES_GLOBALCHAT_H
#define SOPRAMESSAGES_GLOBALCHAT_H

#include <string>
#include "json.hpp"

namespace communication::messages::mods::broadcast {
    class GlobalChat {
    public:
        GlobalChat() = default;
        GlobalChat(std::string senderUserName, std::string information);

        std::string getSenderUserName() const;

        std::string getInformation() const;

        bool operator==(const GlobalChat &rhs) const;

        bool operator!=(const GlobalChat &rhs) const;

        static auto getName() -> std::string;
    private:
        std::string senderUserName, information;
    };

    void to_json(nlohmann::json &j, const GlobalChat &globalChat);
    void from_json(const nlohmann::json &j, GlobalChat &globalChat);
}

#endif //SOPRAMESSAGES_GLOBALCHAT_H
