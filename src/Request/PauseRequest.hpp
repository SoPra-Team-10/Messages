/**
 * @file PauseRequest.hpp
 * @author paul
 * @date 19.03.19
 * @brief Definition of the PauseRequest class
 */

#ifndef SERVER_PAUSEREQUEST_HPP
#define SERVER_PAUSEREQUEST_HPP

#include <string>
#include "json.hpp"

namespace communication::messages::request {
    class PauseRequest {
    public:
        PauseRequest() = default;
        explicit PauseRequest(std::string message);

        std::string getMessage() const;

        static auto getName() -> std::string;

        bool operator==(const PauseRequest &rhs) const;

        bool operator!=(const PauseRequest &rhs) const;

    private:
        std::string message;
    };

    void to_json(nlohmann::json &j, const PauseRequest &pauseRequest);
    void from_json(const nlohmann::json &j, PauseRequest &pauseRequest);
}

#endif //SERVER_PAUSEREQUEST_HPP
