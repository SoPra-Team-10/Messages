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
        static auto getName() -> std::string;

    private:
        std::string errorProducingPayload, information;
    };
}

#endif //SOPRAMESSAGES_PRIVATEERROR_H
