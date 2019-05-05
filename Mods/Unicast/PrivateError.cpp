//
// Created by paulnykiel on 04.05.19.
//

#include "PrivateError.h"


namespace commmunication::messages::mods::broadcast {

    auto PrivateError::getName() -> std::string {
        return "privateError";
    }

    PrivateError::PrivateError(const std::string &errorProducingPayload, const std::string &information)
            : errorProducingPayload(errorProducingPayload), information(information) {}

    std::string PrivateError::getErrorProducingPayload() const {
        return errorProducingPayload;
    }

    std::string PrivateError::getInformation() const {
        return information;
    }

    bool PrivateError::operator==(const PrivateError &rhs) const {
        return errorProducingPayload == rhs.errorProducingPayload &&
               information == rhs.information;
    }

    bool PrivateError::operator!=(const PrivateError &rhs) const {
        return !(rhs == *this);
    }

}
