//
// Created by paulnykiel on 04.05.19.
//

#ifndef SOPRAMESSAGES_PRIVATEWARNING_H
#define SOPRAMESSAGES_PRIVATEWARNING_H

#include <string>
#include "json.hpp"

namespace commmunication::messages::mods::broadcast {
    class PrivateWarning {
    public:
        PrivateWarning(const std::string &warningProducingPayload, const std::string &information);

        std::string getWarningProducingPayload() const;

        std::string getInformation() const;

        bool operator==(const PrivateWarning &rhs) const;

        bool operator!=(const PrivateWarning &rhs) const;

        static auto getName() -> std::string;
    private:
        std::string warningProducingPayload, information;
    };

    void to_json(nlohmann::json &j, const PrivateWarning &privateWarning);
    void from_json(const nlohmann::json &j, PrivateWarning &privateWarning);
}

#endif //SOPRAMESSAGES_PRIVATEWARNING_H
