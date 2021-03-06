/**
 * @file GlobalDebug.hpp
 * @author paul
 * @date 19.03.19
 * @brief Definition of the GlobalDebug class
 */

#ifndef SERVER_GLOBALDEBUG_HPP
#define SERVER_GLOBALDEBUG_HPP

#include <string>
#include "json.hpp"

namespace communication::messages::broadcast {
    class GlobalDebug {
    public:
        GlobalDebug() = default;
        explicit GlobalDebug(std::string information);
        auto getInformation() const -> std::string;

        static auto getName() -> std::string;

        bool operator==(const GlobalDebug &rhs) const;

        bool operator!=(const GlobalDebug &rhs) const;

    private:
        std::string information;
    };

    void to_json(nlohmann::json &j, const GlobalDebug &globalDebug);
    void from_json(const nlohmann::json &j, GlobalDebug &globalDebug);
}

#endif //SERVER_GLOBALDEBUG_HPP
