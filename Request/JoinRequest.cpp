#include <utility>

#include <utility>

/**
 * @file JoinRequest.cpp
 * @author paul
 * @date 19.03.19
 * @brief Definition of the JoinRequest class
 */

#include "JoinRequest.hpp"

namespace communication::messages::request {
    JoinRequest::JoinRequest(std::string lobby, std::string userName, std::string password,
                             bool isArtificialIntelligence, std::vector<std::string> mods) :
                             lobby{std::move(lobby)}, userName{std::move(userName)}, password{std::move(password)},
                             isArtificialIntelligence{isArtificialIntelligence}, mods{std::move(mods)} {}

    auto JoinRequest::getLobby() const -> std::string {
        return this->lobby;
    }

    auto JoinRequest::getUserName() const -> std::string {
        return this->userName;
    }

    auto JoinRequest::getPassword() const -> std::string {
        return this->password;
    }

    auto JoinRequest::getIsAi() const -> bool {
        return this->isArtificialIntelligence;
    }

    auto JoinRequest::getMods() const -> std::vector<std::string> {
        return this->mods;
    }

    auto JoinRequest::getName() -> std::string {
        return "joinRequest";
    }

    bool JoinRequest::operator==(const JoinRequest &rhs) const {
        return lobby == rhs.lobby &&
               userName == rhs.userName &&
               password == rhs.password &&
               isArtificialIntelligence == rhs.isArtificialIntelligence &&
               mods == rhs.mods;
    }

    bool JoinRequest::operator!=(const JoinRequest &rhs) const {
        return !(rhs == *this);
    }

    void to_json(nlohmann::json &j, const JoinRequest &joinRequest) {
        j["lobby"] = joinRequest.getLobby();
        j["userName"] = joinRequest.getUserName();
        j["password"] = joinRequest.getPassword();
        j["isArtificialIntelligence"] = joinRequest.getIsAi();
        j["mods"] = joinRequest.getMods();
    }

    void from_json(const nlohmann::json &j, JoinRequest &joinRequest) {
        joinRequest = JoinRequest{
            j.at("lobby").get<std::string>(),
            j.at("userName").get<std::string>(),
            j.at("password").get<std::string>(),
            j.at("isArtificialIntelligence").get<bool>(),
            j.at("mods")
        };

        auto ok = [](const std::string &s, std::size_t len) {
            for (const auto &c : s) {
                if (!std::isalnum(c)) {
                    return false;
                }
            }
            return s.size() >= 3 && s.size() <= len;
        };

        if (!ok(joinRequest.getLobby(), 40) ||
            !ok(joinRequest.getUserName(), 20)) {
            throw std::runtime_error{"Not valid userName or Lobby"};
        }
    }
}
