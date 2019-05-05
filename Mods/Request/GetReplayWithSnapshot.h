//
// Created by paulnykiel on 04.05.19.
//

#ifndef SOPRAMESSAGES_GETREPLAYWITHSNAPSHOT_H
#define SOPRAMESSAGES_GETREPLAYWITHSNAPSHOT_H

#include <string>
#include "json.hpp"

namespace commmunication::messages::mods::broadcast {
    class GetReplayWithSnapshot {
    public:
        GetReplayWithSnapshot() = default;

        bool operator==(const GetReplayWithSnapshot &rhs) const;

        bool operator!=(const GetReplayWithSnapshot &rhs) const;

        static auto getName() -> std::string;
    };
}

#endif //SOPRAMESSAGES_GETREPLAYWITHSNAPSHOT_H
