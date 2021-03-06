/**
 * @file GetReplay.hpp
 * @author paul
 * @date 19.03.19
 * @brief Definition of the GetReplay class
 */

#ifndef SERVER_GETREPLAY_HPP
#define SERVER_GETREPLAY_HPP

#include <string>
#include "json.hpp"

namespace communication::messages::request {
    class GetReplay {
    public:
        static auto getName() -> std::string;

        bool operator==(const GetReplay &rhs) const;
        bool operator!=(const GetReplay &rhs) const;
    };

    void to_json(nlohmann::json &j, const GetReplay&);
    void from_json(const nlohmann::json&, GetReplay&);
}

#endif //SERVER_GETREPLAY_HPP
