/**
 * @file PrivateDebug.hpp
 * @author paul
 * @date 19.03.19
 * @brief Definition of the PrivateDebug class
 */

#ifndef SERVER_PRIVATEDEBUG_HPP
#define SERVER_PRIVATEDEBUG_HPP

#include <string>
#include "json.hpp"

namespace communication::messages::unicast {
    class PrivateDebug {
    public:
        PrivateDebug() = default;
        explicit PrivateDebug(std::string information);
        auto getInformation() const -> std::string;
        void setInformation(const std::string &information);

        static auto getName() -> std::string;

        bool operator==(const PrivateDebug &rhs) const;

        bool operator!=(const PrivateDebug &rhs) const;

    private:
        std::string information;
    };

    void to_json(nlohmann::json &j, const PrivateDebug &privateDebug);
    void from_json(const nlohmann::json &j, PrivateDebug &privateDebug);
}

#endif //SERVER_PRIVATEDEBUG_HPP
