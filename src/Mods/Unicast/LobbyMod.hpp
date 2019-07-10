/**
 * @file LobbyMod.hpp
 * @author paul
 * @date 06.05.19
 * @brief Declaration of LobbyMod
 */

#ifndef SOPRAMESSAGES_LOBBYMOD_HPP
#define SOPRAMESSAGES_LOBBYMOD_HPP

#include <string>

#include "json.hpp"

namespace communication::messages::mods::unicast {
    struct LobbyEntry {
        std::string name;
        bool matchStarted;
        int connectedUsers;

        bool operator==(const LobbyEntry &rhs) const;

        bool operator!=(const LobbyEntry &rhs) const;
    };

    class LobbyMod {
    public:
        LobbyMod() = default;
        explicit LobbyMod(std::vector<LobbyEntry> lobbies);

        void addLobby(LobbyEntry lobbyEntry);

        std::vector<LobbyEntry> getLobbies() const;

        bool operator==(const LobbyMod &rhs) const;

        bool operator!=(const LobbyMod &rhs) const;

        static auto getName() -> std::string;
    private:
        std::vector<LobbyEntry> lobbies;
    };

    void to_json(nlohmann::json &j, const LobbyEntry &lobbyEntry);
    void from_json(const nlohmann::json &j, LobbyEntry &lobbyEntry);

    void to_json(nlohmann::json &j, const LobbyMod &lobbyMod);
    void from_json(const nlohmann::json &j, LobbyMod &lobbyMod);
}

#endif //SOPRAMESSAGES_LOBBYMOD_HPP
