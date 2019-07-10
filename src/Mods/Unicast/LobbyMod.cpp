/**
 * @file LobbyMod.cpp
 * @author paul
 * @date 06.05.19
 * @brief Definition of Lobby Mod
 */
#include <utility>

#include "LobbyMod.hpp"

namespace communication::messages::mods::unicast {
    LobbyMod::LobbyMod(std::vector<LobbyEntry> lobbies) : lobbies(std::move(lobbies)) {}

    void LobbyMod::addLobby(LobbyEntry lobbyEntry) {
        lobbies.emplace_back(std::move(lobbyEntry));
    }

    std::vector<LobbyEntry> LobbyMod::getLobbies() const {
        return lobbies;
    }

    bool LobbyMod::operator==(const LobbyMod &rhs) const {
        return lobbies == rhs.lobbies;
    }

    bool LobbyMod::operator!=(const LobbyMod &rhs) const {
        return !(rhs == *this);
    }

    auto LobbyMod::getName() -> std::string {
        return "lobbyMod";
    }

    void to_json(nlohmann::json &j, const LobbyEntry &lobbyEntry) {
        j["name"] = lobbyEntry.name;
        j["matchStarted"] = lobbyEntry.matchStarted;
        j["connectedUsers"] = lobbyEntry.connectedUsers;
    }

    void from_json(const nlohmann::json &j, LobbyEntry &lobbyEntry) {
        lobbyEntry.name = j.at("name").get<std::string>();
        lobbyEntry.matchStarted = j.at("matchStarted").get<bool>();
        lobbyEntry.connectedUsers = j.at("connectedUsers").get<int>();
    }

    void to_json(nlohmann::json &j, const LobbyMod &lobbyMod) {
        j["lobbies"] = lobbyMod.getLobbies();
    }

    void from_json(const nlohmann::json &j, LobbyMod &lobbyMod) {
        lobbyMod = LobbyMod{j.at("lobbies").get<std::vector<LobbyEntry>>()};
    }

    bool LobbyEntry::operator==(const LobbyEntry &rhs) const {
        return name == rhs.name &&
               matchStarted == rhs.matchStarted &&
               connectedUsers == rhs.connectedUsers;
    }

    bool LobbyEntry::operator!=(const LobbyEntry &rhs) const {
        return !(rhs == *this);
    }
}
