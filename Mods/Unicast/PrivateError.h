//
// Created by paulnykiel on 04.05.19.
//

#ifndef SOPRAMESSAGES_PRIVATEERROR_H
#define SOPRAMESSAGES_PRIVATEERROR_H

#include <string>
#include "json.hpp"

namespace commmunication::messages::mods::broadcast {
    class PrivateError {
    public:
        PrivateError(const std::string &errorProducingPayload, const std::string &information);

        std::string getErrorProducingPayload() const;

        std::string getInformation() const;

        bool operator==(const PrivateError &rhs) const;

        bool operator!=(const PrivateError &rhs) const;

        static auto getName() -> std::string;
    private:
        std::string errorProducingPayload, information;
    };

    void to_json(nlohmann::json &j, const PrivateError &privateError);
    void from_json(const nlohmann::json &j, PrivateError &privateError);
}

#endif //SOPRAMESSAGES_PRIVATEERROR_H
