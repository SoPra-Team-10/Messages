//
// Created by paulnykiel on 04.05.19.
//

#include "GetReplayWithSnapshot.h"

namespace commmunication::messages::mods::broadcast {

    auto GetReplayWithSnapshot::getName() -> std::string {
        return "getReplayWithSnapshot";
    }

    bool GetReplayWithSnapshot::operator==(const GetReplayWithSnapshot &rhs) const {
        return true;
    }

    bool GetReplayWithSnapshot::operator!=(const GetReplayWithSnapshot &rhs) const {
        return true;
    }
}
