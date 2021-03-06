/**
 * @file LoginGreeting.cpp
 * @author paul
 * @date 19.03.19
 * @brief Definition of the LoginGreeting class
 */

#include "LoginGreeting.hpp"

#include <utility>

namespace communication::messages::broadcast {
    LoginGreeting::LoginGreeting(std::string userName) : userName{std::move(userName)} {}

    auto LoginGreeting::getUserName() const -> std::string {
        return this->userName;
    }

    auto LoginGreeting::getName() -> std::string {
        return "loginGreeting";
    }

    bool LoginGreeting::operator==(const LoginGreeting &rhs) const {
        return userName == rhs.userName;
    }

    bool LoginGreeting::operator!=(const LoginGreeting &rhs) const {
        return !(rhs == *this);
    }

    void to_json(nlohmann::json &j, const LoginGreeting &loginGreeting) {
        j["userName"] = loginGreeting.getUserName();
    }

    void from_json(const nlohmann::json &j, LoginGreeting &loginGreeting) {
        loginGreeting = LoginGreeting{
            j.at("userName").get<std::string>()
        };
    }
}
