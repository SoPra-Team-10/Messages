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
        static auto getName() -> std::string;

    private:
        std::string warningProducingPayload, information;
    };
}

#endif //SOPRAMESSAGES_PRIVATEWARNING_H
