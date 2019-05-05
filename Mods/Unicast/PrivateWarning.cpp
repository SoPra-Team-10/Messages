//
// Created by paulnykiel on 04.05.19.
//

#include "PrivateWarning.h"

namespace commmunication::messages::mods::broadcast {

    auto PrivateWarning::getName() -> std::string {
        return "privateWarning";
    }

    PrivateWarning::PrivateWarning(const std::string &warningProducingPayload, const std::string &information)
            : warningProducingPayload(warningProducingPayload), information(information) {}

    std::string PrivateWarning::getWarningProducingPayload() const {
        return warningProducingPayload;
    }

    std::string PrivateWarning::getInformation() const {
        return information;
    }

    bool PrivateWarning::operator==(const PrivateWarning &rhs) const {
        return warningProducingPayload == rhs.warningProducingPayload &&
               information == rhs.information;
    }

    bool PrivateWarning::operator!=(const PrivateWarning &rhs) const {
        return !(rhs == *this);
    }

    void to_json(nlohmann::json &j, const PrivateWarning &privateWarning) {
        j["warningProducingPayload"] = privateWarning.getWarningProducingPayload();
        j["information"] = privateWarning.getInformation();
    }

    void from_json(const nlohmann::json &j, PrivateWarning &privateWarning) {
        privateWarning = PrivateWarning{
            j.at("warningProducingPayload").get<std::string>(),
            j.at("information").get<std::string>()
        };
    }
}
