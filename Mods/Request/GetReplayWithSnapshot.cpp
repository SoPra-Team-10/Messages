//
// Created by paulnykiel on 04.05.19.
//

#include "GetReplayWithSnapshot.h"

namespace communication::messages::mods::request {

    auto GetReplayWithSnapshot::getName() -> std::string {
        return "getReplayWithSnapshot";
    }

    bool GetReplayWithSnapshot::operator==(const GetReplayWithSnapshot &) const {
        return true;
    }

    bool GetReplayWithSnapshot::operator!=(const GetReplayWithSnapshot &) const {
        return true;
    }

    void to_json(nlohmann::json &, const GetReplayWithSnapshot &) {}

    void from_json(const nlohmann::json &, GetReplayWithSnapshot &) {}
}
