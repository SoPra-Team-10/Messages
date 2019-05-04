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
        static auto getName() -> std::string;
    };
}

#endif //SOPRAMESSAGES_GETREPLAYWITHSNAPSHOT_H
