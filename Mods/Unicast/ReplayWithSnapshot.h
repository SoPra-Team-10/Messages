//
// Created by paulnykiel on 04.05.19.
//

#ifndef SOPRAMESSAGES_REPLAYWITHSNAPSHOT_H
#define SOPRAMESSAGES_REPLAYWITHSNAPSHOT_H

#include <string>
#include "json.hpp"

namespace commmunication::messages::mods::broadcast {
    class ReplayWithSnapshot {
    public:
        static auto getName() -> std::string;
    };
}

#endif //SOPRAMESSAGES_REPLAYWITHSNAPSHOT_H
