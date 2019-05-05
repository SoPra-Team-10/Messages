/**
 * @file JoinRequest.hpp
 * @author paul
 * @date 19.03.19
 * @brief Definition of the JoinRequest class
 */

#ifndef SERVER_JOINREQUEST_HPP
#define SERVER_JOINREQUEST_HPP

#include <string>
#include <types.hpp>
#include "json.hpp"

namespace communication::messages::request {
    class JoinRequest {
    public:
        JoinRequest() = default;
        JoinRequest(std::string lobby, std::string userName, std::string password,
                bool isArtificialIntelligence = false, std::vector<types::Mods> mods = {});
        auto getLobby() const -> std::string;
        auto getUserName() const -> std::string;
        auto getPassword() const -> std::string;
        auto getIsAi() const -> bool;
        auto getMods() const -> std::vector<types::Mods >;

        static auto getName() -> std::string;

        bool operator==(const JoinRequest &rhs) const;

        bool operator!=(const JoinRequest &rhs) const;

    private:
        std::string lobby, userName, password; // Very secure, much hash
        bool isArtificialIntelligence{};
        std::vector<types::Mods> mods;
    };

    void to_json(nlohmann::json &j, const JoinRequest &joinRequest);
    void from_json(const nlohmann::json &j, JoinRequest &joinRequest);
}

#endif //SERVER_JOINREQUEST_HPP
