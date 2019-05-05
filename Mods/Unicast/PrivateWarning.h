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
}

#endif //SOPRAMESSAGES_PRIVATEWARNING_H
