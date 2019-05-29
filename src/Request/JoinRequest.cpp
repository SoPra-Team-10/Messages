/**
 * @file JoinRequest.cpp
 * @author paul
 * @date 19.03.19
 * @brief Definition of the JoinRequest class
 */

#include "JoinRequest.hpp"

#include <utility>

namespace communication::messages::request {
    JoinRequest::JoinRequest(std::string lobby, std::string userName, std::string password,
                             bool isArtificialIntelligence, std::vector<types::Mods> mods) :
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

    auto JoinRequest::getMods() const -> std::vector<types::Mods> {
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
        j["mods"] = nlohmann::json::array();
        for (const auto &mod : joinRequest.getMods()) {
            j["mods"].emplace_back(types::toString(mod));
        }
    }

    void from_json(const nlohmann::json &j, JoinRequest &joinRequest) {
        std::vector<types::Mods> mods;
        for (const auto &mod : j.at("mods")) {
            mods.emplace_back(types::fromStringMod(mod.get<std::string>()));
        }

        joinRequest = JoinRequest{
            j.at("lobby").get<std::string>(),
            j.at("userName").get<std::string>(),
            j.at("password").get<std::string>(),
            j.at("isArtificialIntelligence").get<bool>(),
            mods
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
